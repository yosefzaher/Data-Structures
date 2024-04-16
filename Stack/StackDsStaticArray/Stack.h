#ifndef _STACK_H_ //File Guard
#define _STACK_H_

#include "DataType.h"

#define MAX_SIZE 5
#define ZERO_INIT 0
#define ZERO 0

typedef enum{
    R_Nok = 0,
    R_Ok,
}Return_Status ;

typedef enum{
    Stack_Empty ,
    Stack_Full ,
    Stack_NotFull ,
}Stack_Status ;

typedef struct{

    uint32 Stack_Pointer ;
    uint32 data[MAX_SIZE] ;

}Stack_ds ;


/**
 * @brief   Check the stack if Full ?
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the Stack
 **/
static Stack_Status Stack_Is_Full(Stack_ds *My_Stack) ;

/**
 * @brief   Check the stack if Empty ?
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the Stack
 **/
static Stack_Status Stack_Is_Empty(Stack_ds *My_Stack) ;

/**
 * @brief   Initialization the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Init(Stack_ds *My_Stack) ;

/**
 * @brief   Push element in the top of stack
 * @param   My_Stack Pointer point to the stack
 * @param   Element that will pushed in the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Push(Stack_ds *My_Stack ,uint32 Element) ;

/**
 * @brief   remove the top element in the stack and return it
 * @param   My_Stack Pointer point to the stack
 * @param   pointer to return poped element through it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Pop(Stack_ds *My_Stack ,int32 *Element) ;

/**
 * @brief   return the top element in the stack
 * @param   My_Stack Pointer point to the stack
 * @param   pointer to return peeked element through it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Peek(Stack_ds *My_Stack ,int32 *Element) ;

/**
 * @brief   search for specific element in the stack and return its index
 * @param   My_Stack Pointer point to the stack
 * @param   Element to search for it
 * @param   Index Pointer to return index in it
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Search(Stack_ds *My_Stack ,uint32 Element ,int32 *Index) ;

/**
 * @brief   Display the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Display(Stack_ds *My_Stack) ;

/**
 * @brief   Display the size of the stack
 * @param   My_Stack Pointer point to the stack
 * @retval  Status of the process OK or Not Ok
 **/
Return_Status Stack_Size(Stack_ds *My_Stack ,uint32 *Size);


#endif // _STACK_H_
