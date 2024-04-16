#include <stdio.h>
#include <stdlib.h>
#include "QueueDS.h"

/**
  * @brief  Check if the queue is full or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue) ;

/**
  * @brief  Check if the queue is Empty or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue);


/**
  * @brief  insert an element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Init(Queue_t *My_Queue){
    Return_Status Status = QUEUE_NOK ;
    if(NULL == My_Queue){
        Status = QUEUE_NOK ;
    }
    else
    {
        My_Queue->Queue_Counter = ZERO_INIIT ;
        My_Queue->Queue_Front = -1 ;
        My_Queue->Queue_Rear = -1 ;
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
  * @brief  insert an element in the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) The Element that will be inserted inthe Queue
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Enqueue(Queue_t *My_Queue ,uint32_t Item){
    Return_Status Status = QUEUE_NOK ;
    if(NULL == My_Queue){
        Status = QUEUE_NOK ;
    }
    else
    {
        if(Queue_Is_Full(My_Queue) == QUEUE_FULL)
        {
            Status = QUEUE_NOK ;
        }
        else
        {
            My_Queue->Queue_Rear = ZERO ;
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
  * @param  (Item) Pointer to return the front Element that removed from the queue
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Dequeue(Queue_t *My_Queue ,uint32_t *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item)){
        Status = QUEUE_NOK ;
    }
    else
    {
        if(Queue_Is_Empty(My_Queue) == QUEUE_EMPTY)
        {
            Status = QUEUE_NOK ;
            Item = NULL ;
        }
        else
        {
            My_Queue->Queue_Rear = ZERO ;
            *Item = My_Queue->Queue_Array[My_Queue->Queue_Front] ;
            (My_Queue->Queue_Front)-- ;
            (My_Queue->Queue_Counter)-- ;
            Status = QUEUE_OK ;
        }
    }
    return Status ;
}

/**
  * @brief  return an element from the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) Pointer to return the rear Element from the queue
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Queue_Rear(Queue_t *My_Queue ,uint32_t *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item)){
        Status = QUEUE_NOK ;
        Item = NULL ;
    }
    else
    {
        if(Queue_Is_Empty(My_Queue) == QUEUE_EMPTY)
        {
            Status = QUEUE_NOK ;
            Item = NULL ;
        }
        else
        {
            *Item = My_Queue->Queue_Array[My_Queue->Queue_Rear] ;
            Status = QUEUE_OK ;
        }
    }
    return Status ;
}

/**
  * @brief  return an element from the front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) Pointer to return the front Element from the queue
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Queue_Front(Queue_t *My_Queue ,uint32_t *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item)){
        Status = QUEUE_NOK ;
        Item = NULL ;
    }
    else
    {
        if(Queue_Is_Empty(My_Queue) == QUEUE_EMPTY)
        {
            Status = QUEUE_NOK ;
            Item = NULL ;
        }
        else
        {
            *Item = My_Queue->Queue_Array[My_Queue->Queue_Front] ;
            Status = QUEUE_OK ;
        }
    }
    return Status ;
}


/**
  * @brief  Display all Element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Queue_Display(Queue_t *My_Queue){
    Return_Status Status = QUEUE_NOK ;
    uint32_t L_Counter = ZERO_INIIT ;
    if((NULL == My_Queue)){
        Status = QUEUE_NOK ;
    }
    else
    {
        for(L_Counter = ZERO ; L_Counter < My_Queue->Queue_Counter ; L_Counter++)
        {
            printf("QUEUE[%d] = %d \n",L_Counter,My_Queue->Queue_Array[L_Counter]) ;
        }
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
  * @brief  return the number of the element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
Return_Status Queue_Length(Queue_t *My_Queue,uint32_t *Item){
    Return_Status Status = QUEUE_NOK ;
    if((NULL == My_Queue) || (NULL == Item)){
        Status = QUEUE_NOK ;
    }
    else
    {
        *Item = My_Queue->Queue_Counter ;
        Status = QUEUE_OK ;
    }
    return Status ;
}

/**
  * @brief  Check if the queue is full or not
  * @param  (My_Queue) Pointer to the queue Ds
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Full(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    if(NULL == My_Queue){

    }
    else
    {
        if(My_Queue->Queue_Counter == MAX_SIZE)
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
  * @pre    Used (Return_Status Queue_Init(Queue_t *My_Queue)) Function
  * @retval The status of the process
**/
static Queue_Status Queue_Is_Empty(Queue_t *My_Queue){
    Queue_Status Status = QUEUE_EMPTY ;
    if(NULL == My_Queue){

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
