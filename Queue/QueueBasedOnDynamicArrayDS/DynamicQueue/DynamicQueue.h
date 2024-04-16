#ifndef _DYNAMICQUEUE_H_
#define _DYNAMICQUEUE_H_

#include "DataType.h"

#define ZERO_INIT 0
#define ZERO 0

typedef struct{
    void **Queue_Array ;
    int32_t Queue_Rear ;
    int32_t Queue_Front ;
    uint32_t Queue_Counter ;
    uint32_t Queue_MaxSize ;
}Queue_t ;

typedef enum{
    QUEUE_NOK = 0 ,
    QUEUE_OK
}Return_Status ;

typedef enum{
    QUEUE_EMPTY = 0,
    QUEUE_FULL ,
    QUEUE_NOT_FULL
}Queue_Status;

/**
  * @brief  Create the Queue DS in the heap and return the address of
            the booked space in Queue_t Type Pointer By create Struct
            object first after that Create the Queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Max_Size) the Max size for the queue Ds
  * @retval The status of the process
**/
Queue_t * Queue_Create(Return_Status *Status ,uint32_t Max_Size);

/**
  * @brief  Free the Booked space from the heap by free the queue first after that
            free the struct object from the heap
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Destroy(Queue_t *My_Queue) ;

/**
  * @brief  insert an element in the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) void Pointer to The Element that will be inserted in the Queue
  * @retval The status of the process
**/
Return_Status Enqueue(Queue_t *My_Queue ,void *Item) ;

/**
  * @brief  remove an element from the front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the front Element that removed from the queue
**/
void* Dequeue(Queue_t *My_Queue ,Return_Status *Status) ;

/**
  * @brief  return an element from the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the rear Element
**/
void* Queue_Rear(Queue_t *My_Queue ,Return_Status *Status) ;

/**
  * @brief  return an element from the Front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Status) Pointer to return the Status of the process in it
  * @retval  Void Pointer to return the Front Element
**/
void* Queue_Front(Queue_t *My_Queue ,Return_Status *Status) ;

/**
  * @brief  Display all Element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Display(Queue_t *My_Queue) ;

/**
  * @brief  return the number of the element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Length(Queue_t *My_Queue,uint32_t *Item) ;



#endif // _DYNAMICQUEUE_H_
