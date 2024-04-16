#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "DynamicStack.h"


/**
  * @brief  :  create the stack and allocate it in the heap
  * @param  :  Max size of the stack
  * @param  :  pointer to recieve the status of the operation in it
  * @retval :  pointer point to the stack in the heap
**/

Stack_DyDs_t* Stack_Creat(uint32_t *MaxSize ,Stack_Status_t* Status){
    Stack_DyDs_t *My_Stack = NULL ;
    My_Stack = (Stack_DyDs_t *)malloc(sizeof(Stack_DyDs_t)) ;
    if((NULL == My_Stack) || (NULL == MaxSize))
    {
        *Status = Stack_Nok ;
        My_Stack = NULL ;
    }
    else
    {
            My_Stack->Element_Counter = 0 ;
            My_Stack->Max_Size = *MaxSize ;
            My_Stack->Stack_Top = -1 ;
            My_Stack->Stack_Pointer = (void **)calloc(*MaxSize ,sizeof(void **)) ;

            if(NULL == My_Stack->Stack_Pointer)
            {
                *Status = Stack_Nok ;
                free(My_Stack) ;
                My_Stack = NULL ;
            }
            else
            {
                *Status = Stack_Ok ;
            }
    }
    return My_Stack ;
}

/**
  * @brief  :  free the stack from the heap
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the Stack status
  * @retval :
**/
Stack_DyDs_t* Stack_Destroy(Stack_DyDs_t *My_Stack ,Stack_Status_t* Status){
    if((NULL == My_Stack) || (NULL == Status))
    {
        *Status = Stack_Nok ;
    }
    else
    {
        free(My_Stack->Stack_Pointer) ;
        free(My_Stack) ;
        My_Stack = NULL ;
        *Status = Stack_Ok ;
    }
    return My_Stack ;
}

/**
  * @brief  :  Push the item in the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the item
  * @retval :  status of the process
**/
Stack_Status_t Stack_Push(Stack_DyDs_t *My_Stack ,void *Item){
    Stack_Status_t Status = Stack_Nok ;
    uint16_t L_Counter = ZERO_INIT ;
    if((NULL == My_Stack) || (NULL == Item))
    {
        Status = Stack_Nok ;
    }
    else
    {
        if(Stack_IsFull(My_Stack) == Stack_Full)
        {
            printf("Stack Now is Full :( \n") ;
            printf("We Now Booked A Bigger Space") ;

            for(L_Counter = ZERO ; L_Counter < 13 ; L_Counter++)
            {
                printf(".") ;
                Sleep(200) ;
            }
            printf("\n") ;
            My_Stack->Stack_Pointer = (void **)realloc(My_Stack->Stack_Pointer ,2*(My_Stack->Max_Size*sizeof(void **))) ;
            if(!(My_Stack->Stack_Pointer))
            {
                Status = Stack_Nok ;
                printf("Can't Push Any Another Element :(") ;
            }
            else
            {
                Status = Stack_Ok ;
                (My_Stack->Stack_Top)++ ;
                My_Stack->Stack_Pointer[My_Stack->Stack_Top] = Item ;
                (My_Stack->Element_Counter)++ ;
                My_Stack->Max_Size *= 2 ;
            }
        }
        else
        {
            Status = Stack_Ok ;
            (My_Stack->Stack_Top)++ ;
            My_Stack->Stack_Pointer[My_Stack->Stack_Top] = Item ;
            (My_Stack->Element_Counter)++ ;

        }
    }
    return Status ;
}

/**
  * @brief  :  remove the top item from the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the poped item
  * @retval :  status of the process
**/
void* Stack_Pop(Stack_DyDs_t *My_Stack ,Stack_Status_t *Status){
    void *Num = NULL ;
    if((NULL == My_Stack) || (NULL == Status))
    {
        *Status = Stack_Nok ;
    }
    else
    {
        if(Stack_IsEmpty(My_Stack) == Stack_Empty)
        {
            *Status = Stack_Nok ;
        }
        else
        {
            Num = My_Stack->Stack_Pointer[My_Stack->Stack_Top];
            (My_Stack->Element_Counter)-- ;
            (My_Stack->Stack_Top)-- ;
            *Status = Stack_Ok ;
        }
    }
    return Num ;
}

/**
  * @brief  :  return the top item from the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the peeked item
  * @retval :  status of the process
**/
void* Stack_Peek(Stack_DyDs_t *My_Stack ,Stack_Status_t *Status){
    void *Num = NULL ;
    if((NULL == My_Stack) || (NULL == Status))
    {
        *Status = Stack_Nok ;
    }
    else
    {
        if(Stack_IsEmpty(My_Stack) == Stack_Empty)
        {
            *Status = Stack_Nok ;
        }
        else
        {
            Num = My_Stack->Stack_Pointer[My_Stack->Stack_Top] ;

            *Status = Stack_Ok ;
        }
    }
    return Num ;
}

/**
  * @brief  :  return the size of the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the size of the stack
  * @retval :  status of the process
**/
Stack_Status_t Stack_Size(Stack_DyDs_t *My_Stack ,int32_t *Size){
    Stack_Status_t Status = Stack_Nok ;
    if((NULL == My_Stack) || (NULL == Size))
    {
        Status = Stack_Nok ;
    }
    else
    {
        Size = My_Stack->Element_Counter ;
        Status = Stack_Ok ;
    }
    return Status ;
}

/**
  * @brief  :  display all the element in the stack
  * @param  :  pointer point to the stack
  * @retval :  status of the process
  * @pre    :  all the element in the stack from the same data type --> uint32_t
**/
Stack_Status_t Stack_Display(Stack_DyDs_t *My_Stack){
    Stack_Status_t Status = Stack_Nok ;
    int32_t L_Counter = ZERO_INIT ;
    int32_t L_Counter1 = ZERO_INIT ;
    if(NULL == My_Stack)
    {
        Status = Stack_Nok ;
    }
    else
    {
        for(L_Counter = My_Stack->Stack_Top ; L_Counter >= 0 ; L_Counter--)
        {
            printf("Stack[%d] = %d \n",L_Counter1,*((int32_t *)(My_Stack->Stack_Pointer[L_Counter]))) ;
            L_Counter1++ ;
        }
        Status = Stack_Ok ;
    }
    return Status ;
}

/**
  * @brief  :  Check if the stack is empty or not
  * @param  :  pointer point to the stack
  * @retval :  Stack status
**/
boolean_t Stack_IsEmpty(Stack_DyDs_t * My_Stack)
{
    boolean_t Stack_S = Stack_Empty ;

    if(NULL == My_Stack)
    {
        Stack_S = Stack_Nok ;
    }
    else
    {
        if((My_Stack->Element_Counter) == (ZERO))
        {
            Stack_S = Stack_Empty ;
        }
        else
        {
            Stack_S = Stack_NotFull ;
        }
    }
    return Stack_S ;
}

/**
  * @brief  :  Check if the stack is full or not
  * @param  :  pointer point wto the stack
  * @retval :  Stack status
**/
boolean_t Stack_IsFull(Stack_DyDs_t * My_Stack)
{
    boolean_t Stack_S = Stack_Empty ;

    if(NULL == My_Stack)
    {
        Stack_S = Stack_Nok ;
    }
    else
    {
        if((My_Stack->Element_Counter) == (My_Stack->Max_Size))
        {
            Stack_S = Stack_Full ;
        }
        else
        {
            Stack_S = Stack_NotFull ;
        }
    }
    return Stack_S ;
}
