#ifndef _QUEUEDS_H_
#define _QUEUEDS_H_

#include "DataType.h"
#include "DynamicStack.h"

typedef struct{
    Stack_DyDs_t *StackIn ;
    Stack_DyDs_t *StackOut ;
    int32_t Queue_Rear ;
    int32_t Queue_Front ;
}Queue_t ;

typedef enum{
    QUEUE_NOK = ZERO ,
    QUEUE_OK
}Return_Status ;

typedef enum{
    QUEUE_EMPTY = ZERO ,
    QUEUE_FULL ,
    QUEUE_NOT_FULL
}Queue_Status ;

typedef enum{
    False = 0 ,
    True
}Boolean_Value ;


/**
 * @brief Create the Queue using two Dynamic Stack in the Heap
 * @param (Status) Pointer to return the status of the process in it
 * @param (MaxSize) the max size to initialize the queue with it
 * @retval return the address of the queue created
*/
Queue_t* Queue_Create(Return_Status* Status,uint32_t *MaxSize) ;

/**
 * @brief Free the queue from the Heap
 * @param (My_Queue) Pointer point to the Queue in the heap
 * @retval the status of the process
*/
Return_Status Queue_Destroy(Queue_t* My_Queue) ;

/**
 * @brief insert an elelment in the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Item) Void Pointer Point to the element that will be inserted in the Queue
 * @retval the status of the process
*/
Return_Status Enqueue(Queue_t *My_Queue ,void *Item) ;

/**
 * @brief Remove the Front Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Dequeued Element
*/
void* Dequeue(Queue_t *My_Queue ,Return_Status *Status) ;

/**
 * @brief return the Rear Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Rear Element
*/
void* Rear_Queue(Queue_t *My_Queue ,Return_Status *Status) ;

/**
 * @brief return the Front Element From the Queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @param (Status) Pointer to return the Status of the process in it
 * @retval Void Pointer point to the Front Element
*/
void* Front_Queue(Queue_t *My_Queue ,Return_Status *Status) ;

/**
 * @brief return the number of the elements in the queue
 * @param (My_Queue) Pointer to the Queue in the Heap
 * @retval the status of the process
*/
Return_Status Queue_Length(Queue_t *My_Queue ,uint32_t *Len) ;













































#endif // _QUEUEDS_H_
