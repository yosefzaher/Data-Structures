#ifndef _DYNAMICSTACK_H_
#define _DYNAMICSTACK_H_

#include "DataType.h"

#define ZERO_INIT 0
#define ZERO 0

#define MAX_SIZE 5

typedef struct{
    void **Stack_Pointer ;      /*Pointer point to the array that allocated in the heap*/
    int32_t Element_Counter ;   /*has the actual number of the element in the stack*/
    uint32_t Max_Size ;         /*has the maximum number of the element in the stack*/
    int32_t Stack_Top ;         /*has the index of the top element in the stack*/
}Stack_DyDs_t ;

typedef enum{
    Stack_Nok = 0 ,     /*operation in the stack isn't performed successfully*/
    Stack_Ok ,          /*operation in the stack is performed successfully*/
    Stack_Full ,        /*Stack is Full*/
    Stack_Empty ,       /*Stack is empty*/
    Stack_NotFull ,     /*Stack is not full*/
}Stack_Status_t ;

/**
  * @brief  :  create the stack and allocate it in the heap
  * @param  :  Max size of the stack
  * @param  :  pointer to recieve the status of the operation in it
  * @retval :  pointer point to the stack in the heap
**/
Stack_DyDs_t* Stack_Creat(uint32_t MaxSize ,Stack_Status_t* Status) ;

/**
  * @brief  :  Check if the stack is empty or not
  * @param  :  pointer point to the stack
  * @retval :  1 if the stack is empty , 0 if the stack is not empty
**/
Stack_DyDs_t* Stack_Destroy(Stack_DyDs_t *My_Stack ,Stack_Status_t* Status) ;

/**
  * @brief  :  Push the item in the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the item
  * @retval :  status of the process
**/
Stack_Status_t Stack_Push(Stack_DyDs_t *My_Stack ,void *Item) ;

/**
  * @brief  :  remove the top item from the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the poped item
  * @retval :  status of the process
**/
void* Stack_Pop(Stack_DyDs_t *My_Stack ,Stack_Status_t *Status) ;

/**
  * @brief  :  return the top item from the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the peeked item
  * @retval :  status of the process
**/
void* Stack_Peek(Stack_DyDs_t *My_Stack ,Stack_Status_t *Status) ;

/**
  * @brief  :  return the size of the stack
  * @param  :  pointer point to the stack
  * @param  :  pointer point to the size of the stack
  * @retval :  status of the process
**/
Stack_Status_t Stack_Size(Stack_DyDs_t *My_Stack ,int32_t *Size) ;

/**
  * @brief  :  display all the element in the stack
  * @param  :  pointer point to the stack
  * @retval :  status of the process
**/
Stack_Status_t Stack_Display(Stack_DyDs_t *My_Stack) ;












#endif // _DYNAMICSTACK_H_
