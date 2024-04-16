#include <stdio.h>
#include <stdlib.h>
#include "QueueDS.h"

Queue_t Queue ;
Return_Status Status = QUEUE_NOK ;
Queue_Status QStatus = QUEUE_EMPTY ;
uint32_t Num = ZERO_INIIT ;

int main()
{
    Status = Queue_Init(&Queue) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    Status = Enqueue(&Queue,12) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,13) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,14) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,15) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,16) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,17) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,18) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    Status = Queue_Display(&Queue) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    printf("Rear Queue = %d \n",Queue.Queue_Array[Queue.Queue_Rear]) ;
    printf("Front Queue = %d \n",Queue.Queue_Array[Queue.Queue_Front]) ;
    printf("Number of element in the queue = %d \n",Queue.Queue_Counter) ;
    printf("==========================================================\n") ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    printf("==========================================================\n") ;
    Status = Queue_Display(&Queue) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    printf("Rear Queue = %d \n",Queue.Queue_Array[Queue.Queue_Rear]) ;
    printf("Front Queue = %d \n",Queue.Queue_Array[Queue.Queue_Front]) ;
    printf("Number of element in the queue = %d \n",Queue.Queue_Counter) ;
    printf("==========================================================\n") ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    Status = Dequeue(&Queue,&Num) ;printf("Status = %d \t",Status) ;printf("Dequeued Element = %d \n",Num) ;
    printf("==========================================================\n") ;
    Status = Queue_Display(&Queue) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    printf("Rear Queue = %d \n",Queue.Queue_Array[Queue.Queue_Rear]) ;
    printf("Front Queue = %d \n",Queue.Queue_Array[Queue.Queue_Front]) ;
    printf("Number of element in the queue = %d \n",Queue.Queue_Counter) ;
    printf("==========================================================\n") ;
    Status = Enqueue(&Queue,123) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,134) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,145) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,156) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,167) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,178) ;printf("Status = %d \n",Status) ;
    Status = Enqueue(&Queue,198) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    Status = Queue_Display(&Queue) ;printf("Status = %d \n",Status) ;
    printf("==========================================================\n") ;
    printf("Rear Queue = %d \n",Queue.Queue_Array[Queue.Queue_Rear]) ;
    printf("Front Queue = %d \n",Queue.Queue_Array[Queue.Queue_Front]) ;
    printf("Number of element in the queue = %d \n",Queue.Queue_Counter) ;
    printf("==========================================================\n") ;
    return 0;
}
