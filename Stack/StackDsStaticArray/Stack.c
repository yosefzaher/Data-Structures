#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/**
 * @brief   Check the stack if Full ?
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the Stack
 **/
static Stack_Status Stack_Is_Full(Stack_ds *My_Stack)
{
    if(NULL == My_Stack)
    {
        return -1 ;
    }
    else
    {
        if((My_Stack->Stack_Pointer) == (MAX_SIZE-1))
        {
            return Stack_Full ;
        }
        else
        {
            return Stack_NotFull ;
        }
    }
}

/**
 * @brief   Check the stack if Empty ?
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the Stack
 **/
static Stack_Status Stack_Is_Empty(Stack_ds *My_Stack)
{
    if(NULL == My_Stack)
    {
        return -1 ;
    }
    else
    {
        if((My_Stack->Stack_Pointer) == -1 )
        {
            return Stack_Empty ;
        }
        else
        {
            return Stack_NotFull ;
        }
    }

}

/**
 * @brief   Initialization the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Init(Stack_ds *My_Stack)
{
    Return_Status RetVal = R_Nok ;
    if(NULL == My_Stack)
    {
        RetVal = R_Nok ;
    }
    else
    {
        My_Stack -> Stack_Pointer = -1 ;
        RetVal = R_Ok ;
    }
    return RetVal ;
}

/**
 * @brief   Push element in the top of stack
 * @param   My_Stack Pointer point to the stack
 * @param   Element that will pushed in the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Push(Stack_ds *My_Stack ,uint32 Element)
{
    Stack_Status Status = Stack_Empty ;
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack)
    {
        retval = R_Nok ;
    }
    else
    {
       Status = Stack_Is_Full(My_Stack) ;
       if(Stack_Full == Status)
       {
           retval = R_Nok ;
       }
       else
       {
           My_Stack->Stack_Pointer++ ;
           My_Stack->data[My_Stack->Stack_Pointer] =  Element ;
           retval = R_Ok ;
       }
    }
    return retval ;
}

/**
 * @brief   remove the top element in the stack and return it
 * @param   My_Stack Pointer point to the stack
 * @param   pointer to return poped element through it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Pop(Stack_ds *My_Stack ,int32 *Element)
{
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack || NULL == Element)
    {
        retval = R_Nok ;
        *Element = -1 ;
    }
    else
    {
        Stack_Status Status = Stack_Empty ;
        Status = Stack_Is_Empty(My_Stack) ;
        if(Stack_Empty == Status)
        {
            retval = R_Nok ;
            *Element = -1 ;
        }
        else
        {
            *Element = My_Stack->data[My_Stack->Stack_Pointer] ;
            My_Stack->Stack_Pointer-- ;
            retval = R_Ok ;
        }
    }
    return retval ;
}

/**
 * @brief   return the top element in the stack
 * @param   My_Stack Pointer point to the stack
 * @param   pointer to return peeked element through it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Peek(Stack_ds *My_Stack ,int32 *Element)
{
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack || NULL == Element)
    {
        retval = R_Nok ;
        *Element = -1 ;
    }
    else
    {
        Stack_Status Status = Stack_Empty ;
        Status = Stack_Is_Empty(My_Stack) ;
        if(Stack_Empty == Status)
        {
            retval = R_Nok ;
            *Element = -1 ;
        }
        else
        {
            *Element = My_Stack->data[My_Stack->Stack_Pointer] ;
            retval = R_Ok ;
        }
    }
    return retval ;
}

/**
 * @brief   search for specific element in the stack and return its index
 * @param   My_Stack Pointer point to the stack
 * @param   Element to search for it
 * @param   Index Pointer to return index in it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Search(Stack_ds *My_Stack ,uint32 Element ,int32 *Index)
{
    uint16 Counter = ZERO_INIT ;
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack || NULL == Index)
    {
        retval = R_Nok ;
        *Index = -1 ;
    }
    else
    {
        Stack_Status Status = Stack_Empty ;
        Status = Stack_Is_Empty(My_Stack) ;
        if(Stack_Empty == Status)
        {
            retval = R_Nok ;
            *Index = -1 ;
        }
        else
        {
            for(Counter = ZERO_INIT ; Counter <= My_Stack->Stack_Pointer ;Counter++)
            {
                if((My_Stack->data[My_Stack->Stack_Pointer]) == (Element))
                {
                    *Index = My_Stack->Stack_Pointer ;
                    retval = R_Ok ;
                    break ;
                }
            }
        }
    }
    return retval ;
}

/**
 * @brief   Display the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Display(Stack_ds *My_Stack)
{
    uint16 Counter = ZERO_INIT ;
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack)
    {
        retval = R_Nok ;
        printf("Error! NULL Pointer. \n") ;
    }
    else
    {
        Stack_Status Status = Stack_Empty ;
        Status = Stack_Is_Empty(My_Stack) ;

        if(Stack_Empty == Status)
        {
            printf("Stack is Empty. \n");
        }
        else
        {
            for(Counter = ZERO ; Counter <= My_Stack->Stack_Pointer ; Counter++)
            {
                printf("Stack[%d] = %d \n",Counter,My_Stack->data[My_Stack->Stack_Pointer - Counter]);
            }
        }
    }
    return retval ;
}

/**
 * @brief   Display the size of the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Size(Stack_ds *My_Stack ,uint32 *Size){
    Return_Status retval = R_Nok ;
    if(NULL == My_Stack || NULL == Size)
    {
        retval = R_Nok ;
    }
    else{
        *Size = (My_Stack->Stack_Pointer+1) ;
        retval = R_Ok ;
    }
    return retval ;
}

