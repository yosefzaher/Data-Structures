#ifndef _QUEUEDS_H_
#define _QUEUEDS_H_

#include "DataType.h"

#define ZERO_INIIT 0
#define ZERO 0

#define MAX_SIZE 5

typedef struct{
    uint32_t Queue_Rear ;
    uint32_t Queue_Front ;
    uint32_t Queue_Counter ;
    uint32_t Queue_Array[MAX_SIZE] ;
}Queue_t ;

typedef enum{
    QUEUE_NOK = 0 ,
    QUEUE_OK
}Return_Status ;

typedef enum{
    QUEUE_EMPTY = 0 ,
    QUEUE_FULL ,
    QUEUE_NOT_FULL
}Queue_Status ;


/**
  * @brief  insert an element in the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @retval The status of the process
**/
Return_Status Queue_Init(Queue_t *My_Queue) ;

/**
  * @brief  insert an element in the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) The Element that will be inserted inthe Queue
  * @retval The status of the process
**/
Return_Status Enqueue(Queue_t *My_Queue ,uint32_t Item) ;

/**
  * @brief  remove an element from the front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) Pointer to return the front Element that removed from the queue
  * @retval The status of the process
**/
Return_Status Dequeue(Queue_t *My_Queue ,uint32_t *Item) ;

/**
  * @brief  return an element from the rear of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) Pointer to return the rear Element from the queue
  * @retval The status of the process
**/
Return_Status Queue_Rear(Queue_t *My_Queue ,uint32_t *Item) ;

/**
  * @brief  return an element from the front of the queue
  * @param  (My_Queue) Pointer to the queue Ds
  * @param  (Item) Pointer to return the front Element from the queue
  * @retval The status of the process
**/
Return_Status Queue_Front(Queue_t *My_Queue ,uint32_t *Item) ;

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



#endif // _QUEUEDS_H_
