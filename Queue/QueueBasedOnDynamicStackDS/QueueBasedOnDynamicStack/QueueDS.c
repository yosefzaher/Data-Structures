#include <stdio.h>
#include <stdlib.h>

#include "QueueDS.h"

//#define DEBUG

/**
 * @brief Check if the Queue is Full or not ?
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval The Queue Status (Full - Not Full)
*/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue) ;

/**
 * @brief Check if the Queue is Empty or not ?
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval The Queue Status (Empty - Not Full)
*/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue) ;

/**
 * @brief Create the Queue using two Dynamic Stack in the Heap
 * @param (Status) Pointer to return the status of the process in it
 * @param (MaxSize) the max size to initialize the queue with it
 * @retval return the address of the queue created
*/
Queue_t* Queue_Create(Return_Status* Status,uint32_t *MaxSize){
#ifdef DEBUG
    printf("Start the Function Of Queue Creation \n") ;
#endif // DEBUG
    Stack_Status_t StackIn_Status = Stack_Nok ;
    Stack_Status_t StackOut_Status = Stack_Nok ;
    Queue_t *My_Queue = NULL ;
#ifdef DEBUG
    printf("Now We Create 1- Stack_Status_t to StackIn\n2- Stack_Status_t to StackOut\n3- Pointer point to Queue_t\n") ;
    printf("Stack Status to StackIn = %d \t",StackIn_Status) ;
    printf("Stack Status to StackOut = %d \n",StackOut_Status) ;
#endif // DEBUG
    if((NULL == Status) || (NULL == MaxSize))
    {
        My_Queue = NULL ;
    }
    else
    {
        My_Queue = (Queue_t *)malloc(sizeof(Queue_t)) ;
        if(NULL == My_Queue)
        {
            *Status = QUEUE_NOK ;
        }
        else
        {
            My_Queue->StackIn = Stack_Creat(MaxSize ,&StackIn_Status) ;
        #ifdef DEBUG
            printf("Status of create StackIn = %d \n",StackIn_Status) ;
        #endif // DEBUG
            My_Queue->StackOut = Stack_Creat(MaxSize ,&StackOut_Status) ;
        #ifdef DEBUG
            printf("Status of create StackIn = %d \n",StackOut_Status) ;
        #endif // DEBUG
            if((NULL == My_Queue->StackIn) || (NULL == My_Queue->StackOut))
            {
                *Status = QUEUE_NOK ;
                My_Queue = NULL ;
            }
            else
            {
                My_Queue->Queue_Rear = 0 ;
                (My_Queue->Queue_Front) = -1 ;
                *Status = QUEUE_OK ;
            }
        }

    }
    return My_Queue ;
}

/**
 * @brief Free the queue from the Heap
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval the status of the process
*/
Return_Status Queue_Destroy(Queue_t* My_Queue){
    Return_Status Status = QUEUE_NOK ;
    if(NULL == My_Queue)
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        free(My_Queue->StackIn->Stack_Pointer) ;
    #ifdef DEBUG
        printf("Free of [My_Queue->StackIn->Stack_Pointer] is done :) \n") ;
    #endif // DEBUG
        free(My_Queue->StackOut->Stack_Pointer) ;
    #ifdef DEBUG
        printf("Free of [My_Queue->StackOut->Stack_Pointer] is done :) \n") ;
    #endif // DEBUG
        free(My_Queue->StackIn) ;
    #ifdef DEBUG
        printf("Free of [My_Queue->StackIn] is done :) \n") ;
    #endif // DEBUG
        free(My_Queue->StackOut) ;
    #ifdef DEBUG
        printf("Free of [My_Queue->StackOut] is done :) \n") ;
    #endif // DEBUG
        free(My_Queue) ;
    #ifdef DEBUG
        printf("Free of [My_Queue] is done :) \n") ;
    #endif // DEBUG
        My_Queue = NULL ;

        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
 * @brief insert an elelment in the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Item) Void Pointer Point to the element that will be inserted in the Queue
 * @retval the status of the process
*/
Return_Status Enqueue(Queue_t *My_Queue ,void *Item){
    Return_Status Status = QUEUE_NOK ;
    Stack_Status_t Stack_Status = Stack_Nok ;
    if((NULL == My_Queue) || (NULL == Item))
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        Stack_Status = Stack_Push(My_Queue->StackIn,Item) ;
        if(Stack_Ok == Stack_Status)
        {
            Status = QUEUE_OK ;
            (My_Queue->Queue_Front)++ ;
        }
        else
        {
            Status = QUEUE_NOK ;
        }
    }
    return Status ;
}

/**
 * @brief Remove the Front Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Dequeued Element
*/
void* Dequeue(Queue_t *My_Queue ,Return_Status *Status){
    uint32_t L_Counter = ZERO_INIT ;
    void *Item = NULL ;
    Return_Status State = QUEUE_NOK ;
    Stack_Status_t S = Stack_Empty ;
    if(NULL == My_Queue || NULL == Status)
    {
        Item = NULL ;
    }
    else
    {
        for(L_Counter = ZERO ; L_Counter < My_Queue->StackIn->Element_Counter ; L_Counter++)
        {
            State = Stack_Push(My_Queue->StackOut,My_Queue->StackIn->Stack_Pointer[(My_Queue->StackIn->Stack_Top) - L_Counter]) ;
        }
        Item = Stack_Pop(My_Queue->StackOut,&S) ;
        My_Queue->StackIn->Element_Counter = 0 ;
        My_Queue->StackIn->Stack_Top = -1 ;
        for(L_Counter = ZERO ; L_Counter < My_Queue->StackOut->Element_Counter ; L_Counter++)
        {
            State = Stack_Push(My_Queue->StackIn,My_Queue->StackOut->Stack_Pointer[(My_Queue->StackOut->Stack_Top) - L_Counter]) ;
        }
        My_Queue->StackOut->Element_Counter = 0 ;
        My_Queue->StackOut->Stack_Top = -1 ;
        *Status = QUEUE_OK ;
        (My_Queue->Queue_Front)-- ;
    }
    return Item ;
}

/**
 * @brief return the Rear Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Rear Element
*/
void* Rear_Queue(Queue_t *My_Queue ,Return_Status *Status){
    void *Item = NULL ;
    if(NULL == My_Queue || NULL == Status)
    {
        Item = NULL ;
    }
    else
    {
        Item = My_Queue->StackIn->Stack_Pointer[My_Queue->StackIn->Stack_Top] ;
        *Status = QUEUE_OK ;
    }
    return Item ;
}

/**
 * @brief return the Front Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Front Element
*/
void* Front_Queue(Queue_t *My_Queue ,Return_Status *Status){
    void *Item = NULL ;
    if(NULL == My_Queue || NULL == Status)
    {
        Item = NULL ;
    }
    else
    {
        Item = My_Queue->StackIn->Stack_Pointer[(My_Queue->StackIn->Stack_Top) - (My_Queue->StackIn->Element_Counter) + 1] ;
        *Status = QUEUE_OK ;
    }
    return Item ;
}

/**
 * @brief return the number of the elements in the queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @retval the status of the process
*/
Return_Status Queue_Length(Queue_t *My_Queue ,uint32_t *Len){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Len))
    {
        Status = QUEUE_NOK ;
        Len = NULL ;
    }
    else
    {
        *Len = My_Queue->StackIn->Element_Counter ;
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
 * @brief Check if the Queue is Full or not ?
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval The Queue Status (Full - Not Full)
*/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    Stack_Status_t StackStatus = Stack_Empty ;
    StackStatus = Stack_IsFull(My_Queue->StackIn) ;
    if(Stack_Full == StackStatus)
    {
        Status = QUEUE_FULL ;
    }
    else
    {
        Status = QUEUE_NOT_FULL ;
    }
    return Status ;
}

/**
 * @brief Check if the Queue is Empty or not ?
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval The Queue Status (Empty - Not Full)
*/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    Stack_Status_t StackStatus = Stack_Empty ;
    StackStatus = Stack_IsEmpty(My_Queue->StackIn) ;
    if(Stack_Empty == StackStatus)
    {
        Status = QUEUE_EMPTY ;
    }
    else
    {
        Status = QUEUE_NOT_FULL ;
    }
    return Status ;
}

