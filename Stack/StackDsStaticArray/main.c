#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack_ds Stack1 ;



int main()
{
    int32 Ptr_Element = ZERO_INIT ;

    char retVal = Stack_Init(&Stack1) ;
    printf("stack one initialization = %d \n",retVal) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    retVal = Stack_Push(&Stack1 ,32) ;
    printf("push first element = %d \n",retVal) ;
    printf("First element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    retVal = Stack_Push(&Stack1 ,54) ;
    printf("push second element = %d \n",retVal) ;
    printf("second element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    retVal = Stack_Push(&Stack1 ,3) ;
    printf("push third element = %d \n",retVal) ;
    printf("third element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    printf("======================================================================================= \n") ;

    retVal = Stack_Display(&Stack1) ;
    printf("\n") ;
    printf("retval = %d \n",retVal) ;

    printf("======================================================================================= \n") ;
    retVal = Stack_Size(&Stack1,&Ptr_Element) ;
    printf("Size operator = %d \n",retVal) ;
    printf("Size of the stack = %d \n",Ptr_Element) ;
    printf("======================================================================================= \n") ;

    retVal = Stack_Search(&Stack1 ,3 ,&Ptr_Element) ;
    printf("Search of the element = %d \n",retVal) ;
    printf("The index of the element = %d \n",Ptr_Element) ;

    printf("======================================================================================= \n") ;

    retVal = Stack_Peek(&Stack1 ,&Ptr_Element) ;
    printf("Peek element = %d \n",retVal) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    printf("Peeked element = %d \n",Ptr_Element) ;

    printf("======================================================================================= \n") ;

    retVal = Stack_Pop(&Stack1 ,&Ptr_Element) ;
    printf("Pop first element = %d \n",retVal) ;
    printf("The poped element = %d \n",Ptr_Element) ;
    printf("First element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    retVal = Stack_Pop(&Stack1 ,&Ptr_Element) ;
    printf("Pop second element = %d \n",retVal) ;
    printf("The poped element = %d \n",Ptr_Element) ;
    printf("second element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    retVal = Stack_Pop(&Stack1 ,&Ptr_Element) ;
    printf("Pop third element = %d \n",retVal) ;
    printf("The poped element = %d \n",Ptr_Element) ;
    printf("third element in the stack = %d \n",Stack1.data[Stack1.Stack_Pointer]) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;

    printf("======================================================================================= \n") ;
    retVal = Stack_Size(&Stack1,&Ptr_Element) ;
    printf("Size operator = %d \n",retVal) ;
    printf("Size of the stack = %d \n",Ptr_Element) ;
    printf("======================================================================================= \n") ;

    retVal = Stack_Search(&Stack1 ,3 ,&Ptr_Element) ;
    printf("Search of the element = %d \n",retVal) ;
    printf("The index of the element = %d \n",Ptr_Element) ;

    printf("======================================================================================= \n") ;

    retVal = Stack_Peek(&Stack1 ,&Ptr_Element) ;
    printf("Peek element = %d \n",retVal) ;
    printf("Stack Pointer = %d \n",Stack1.Stack_Pointer) ;
    printf("Peeked element = %d \n",Ptr_Element) ;

    printf("======================================================================================= \n") ;

    return ZERO ;
}
