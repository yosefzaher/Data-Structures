#include <stdio.h>
#include <stdlib.h>
#include "DynamicQueue.h"


/**
  * @brief  Check if the queue is full or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue);

/**
  * @brief  Check if the queue is Empty or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue);

/**
  * @brief  Create the Queue DS in the heap and return the address of
            the booked space in Queue_t Type Pointer By create Struct
            object first after that Create the Queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Max_Size) the Max size for the queue Ds
  * @retval The status of the process
**/
Queue_t* Queue_Create(Return_Status *Status ,uint32_t Max_Size){
    Queue_t *My_Queue = NULL ;
    if(NULL == Status)
    {
        *Status = QUEUE_NOK ;

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
            My_Queue->Queue_Array = (void **)calloc(Max_Size ,sizeof(void **)) ;
            if(NULL == My_Queue->Queue_Array)
            {
                *Status = QUEUE_NOK ;
                free(My_Queue) ;
                My_Queue = NULL ;
            }
            else
            {
                My_Queue->Queue_Front = -1 ;
                My_Queue->Queue_Rear = -1 ;
                (My_Queue->Queue_Counter) = ZERO ;
                (My_Queue->Queue_MaxSize) = Max_Size ;
                *Status = QUEUE_OK ;
            }
        }
    }

    return My_Queue ;
}

/**
  * @brief  Free the Booked space from the heap by free the queue first after that
            free the struct object from the heap
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Destroy(Queue_t *My_Queue){
    Return_Status Status = QUEUE_NOK ;
    if(NULL == My_Queue)
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        free(My_Queue->Queue_Array) ;
        free(My_Queue) ;
        My_Queue->Queue_Array = NULL ;
        My_Queue = NULL ;
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
  * @brief  insert an element in the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) void Pointer to The Element that will be inserted in the Queue
  * @retval The status of the process
**/
Return_Status Enqueue(Queue_t *My_Queue ,void *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item))
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        if(QUEUE_FULL == Queue_Is_Full(My_Queue))
        {
            (My_Queue->Queue_MaxSize) *= 2 ;
            My_Queue->Queue_Array = (void **)realloc(My_Queue->Queue_Array ,(My_Queue->Queue_MaxSize)*sizeof(void **)) ;
            if(NULL == My_Queue->Queue_Array)
            {
                Status = QUEUE_NOK ;
            }
            else
            {
                My_Queue->Queue_Rear = 0 ;
                (My_Queue->Queue_Front)++ ;
                My_Queue->Queue_Array[My_Queue->Queue_Front] = Item ;
                (My_Queue->Queue_Counter)++ ;
                Status = QUEUE_OK ;
            }
        }
        else
        {
            My_Queue->Queue_Rear = 0 ;
            (My_Queue->Queue_Front)++ ;
            My_Queue->Queue_Array[My_Queue->Queue_Front] = Item ;
            (My_Queue->Queue_Counter)++ ;
            Status = QUEUE_OK ;
        }
    }
    return Status ;
}

/**
  * @brief  remove an element from the front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the front Element that removed from the queue
**/
void* Dequeue(Queue_t *My_Queue ,Return_Status *Status){
    void *Item = NULL ;
    *Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NOK ;
    }
    else
    {
        if(QUEUE_EMPTY == Queue_Is_Empty(My_Queue))
        {
            *Status = QUEUE_NOK ;
            Item = NULL ;
        }
        else
        {
            Item = My_Queue->Queue_Array[My_Queue->Queue_Front]  ;
            (My_Queue->Queue_Front)-- ;
            (My_Queue->Queue_Counter)-- ;
            *Status = QUEUE_OK ;
        }
    }
    return Item ;
}

/**
  * @brief  return an element from the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the rear Element
**/
void* Queue_Rear(Queue_t *My_Queue ,Return_Status *Status){
    void *RearItem = NULL ;
    if((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NOK ;
        RearItem = NULL ;
    }
    else
    {
        RearItem = My_Queue->Queue_Array[My_Queue->Queue_Rear] ;
        *Status = QUEUE_OK ;
    }
    return RearItem ;
}

/**
  * @brief  return an element from the Front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the Front Element
**/
void* Queue_Front(Queue_t *My_Queue ,Return_Status *Status){
    void *FrontItem = NULL ;
    if((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NOK ;
        FrontItem = NULL ;
    }
    else
    {
        FrontItem = My_Queue->Queue_Array[My_Queue->Queue_Front] ;
        *Status = QUEUE_OK ;
    }
    return FrontItem ;
}

/**
  * @brief  Display all Element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @pre    All element should be from the same data type (uint32_t)
  * @retval The status of the process
**/
Return_Status Queue_Display(Queue_t *My_Queue){
    Return_Status Status = QUEUE_NOK ;
    uint32_t L_Counter = ZERO_INIT ;
    if(NULL == My_Queue)
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        for(L_Counter = ZERO ; L_Counter < My_Queue->Queue_Counter ; L_Counter++)
        {
            printf("Queue[%d] = %d \n",L_Counter,*((uint32_t *)(My_Queue->Queue_Array[L_Counter]))) ;
        }
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
  * @brief  return the number of the element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Length(Queue_t *My_Queue,uint32_t *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item))
    {
        Status = QUEUE_NOK ;
    }
    else
    {
        Item = My_Queue->Queue_Counter ;
        Status = QUEUE_OK ;
    }
    return Status ;
}


/**
  * @brief  Check if the queue is full or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    if(NULL == My_Queue)
    {

    }
    else
    {
        if(My_Queue->Queue_Counter == My_Queue->Queue_MaxSize)
        {
            Status = QUEUE_FULL ;
        }
        else
        {
            Status = QUEUE_NOT_FULL ;
        }
    }
    return Status ;
}

/**
  * @brief  Check if the queue is Empty or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    if(NULL == My_Queue)
    {

    }
    else
    {
        if(My_Queue->Queue_Counter == ZERO)
        {
            Status = QUEUE_EMPTY ;
        }
        else
        {
            Status = QUEUE_NOT_FULL ;
        }
    }
    return Status ;
}





































