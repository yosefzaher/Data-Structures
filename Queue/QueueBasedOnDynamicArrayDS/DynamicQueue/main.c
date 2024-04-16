#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "DynamicQueue.h"

Queue_t *Queue = NULL;
void *Num = NULL ;
Return_Status Status = QUEUE_EMPTY ;
uint32_t Max_Size = ZERO_INIT ;
boolean_t Check = ZERO_INIT ;
uint8_t L_Counter = ZERO_INIT ;
uint32_t N1 = 12 ;
uint32_t N2 = 13 ;
uint32_t N3 = 14 ;
uint32_t N4 = 15 ;
uint32_t N5 = 16 ;
uint32_t N6 = 17 ;
uint32_t N7 = 18 ;
uint32_t N8 = 19 ;
uint32_t N9 = 20 ;
uint32_t N10 = 21 ;
uint32_t N11 = 22 ;
uint32_t N12 = 23 ;

float32_t NF = 32.946342 ;
uint8_t NC = 'a' ;
int32_t NN = -23 ;

int main()
{
    printf("Please Enter the Max Size for the dynamic Queue :  ");
    scanf("%d",&Max_Size) ;
    Queue = Queue_Create(&Status ,Max_Size) ;printf("Creating Dynamic Queue Status = %d \n",Status) ;
    printf("Do you want to free the space in the heap : ") ;
    scanf("%d",&Check) ;
    if(!Check){
        printf("===================================================\n") ;
        printf("Queue Counter = %d \n",Queue->Queue_Counter) ;
        printf("Queue Rear = %d \n",Queue->Queue_Rear) ;
        printf("Queue Front = %d \n",Queue->Queue_Front) ;
        printf("Queue Max Size = %d \n",Queue->Queue_MaxSize) ;
        printf("===================================================\n") ;
        Status = Enqueue(Queue ,&N1) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N2) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N3) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N4) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N5) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N6) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N7) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N8) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N9) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N10) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N11) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&N12) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        printf("===================================================\n") ;
        Status = Queue_Display(Queue) ;printf("Status of the Display operation = %d \n",Status) ;
        printf("===================================================\n") ;
        printf("Queue Counter = %d \n",Queue->Queue_Counter) ;
        printf("Queue Rear = %d \n",Queue->Queue_Rear) ;
        printf("Queue Front = %d \n",Queue->Queue_Front) ;
        printf("Queue Max Size = %d \n",Queue->Queue_MaxSize) ;
        printf("===================================================\n") ;
        Num = Queue_Rear(Queue ,&Status);printf("Status of Queue Rear operation = %d \t",Status) ;printf("Rear Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        Num = Queue_Front(Queue ,&Status);printf("Status of Queue Front operation = %d \t",Status) ;printf("Front Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        Status = Enqueue(Queue ,&NF) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&NC) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        Status = Enqueue(Queue ,&NN) ;printf("Status of the Enqueue operation = %d \n",Status) ;
        printf("===================================================\n") ;
        printf("Queue[13] = %f \n",*((float32_t *)(Queue->Queue_Array[Queue->Queue_Front - 2]))) ;
        printf("Queue[14] = %c \n",*((uint8_t *)(Queue->Queue_Array[Queue->Queue_Front - 1]))) ;
        printf("Queue[15] = %d \n",*((int32_t *)(Queue->Queue_Array[Queue->Queue_Front - 0]))) ;
        printf("===================================================\n") ;
        printf("Queue Counter = %d \n",Queue->Queue_Counter) ;
        printf("Queue Rear = %d \n",Queue->Queue_Rear) ;
        printf("Queue Front = %d \n",Queue->Queue_Front) ;
        printf("Queue Max Size = %d \n",Queue->Queue_MaxSize) ;
        printf("===================================================\n") ;
        Num = Queue_Rear(Queue ,&Status);printf("Status of Queue Rear operation = %d \t",Status) ;printf("Rear Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        Num = Queue_Front(Queue ,&Status);printf("Status of Queue Front operation = %d \t",Status) ;printf("Front Item = %d \n",*((int32_t *)Num)) ;
        printf("===================================================\n") ;
        Num = Dequeue(Queue ,&Status) ;printf("Status of Dequeue operation = %d \t",Status) ;printf("Dequeue Item = %d \n",*((int32_t *)Num)) ;
        Num = Dequeue(Queue ,&Status) ;printf("Status of Dequeue operation = %d \t",Status) ;printf("Dequeue Item = %c \n",*((int8_t *)Num)) ;
        Num = Dequeue(Queue ,&Status) ;printf("Status of Dequeue operation = %d \t",Status) ;printf("Dequeue Item = %f \n",*((float32_t *)Num)) ;
        Num = Dequeue(Queue ,&Status) ;printf("Status of Dequeue operation = %d \t",Status) ;printf("Dequeue Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        printf("Queue Counter = %d \n",Queue->Queue_Counter) ;
        printf("Queue Rear = %d \n",Queue->Queue_Rear) ;
        printf("Queue Front = %d \n",Queue->Queue_Front) ;
        printf("Queue Max Size = %d \n",Queue->Queue_MaxSize) ;
        printf("===================================================\n") ;
        Num = Queue_Rear(Queue ,&Status);printf("Status of Queue Rear operation = %d \t",Status) ;printf("Rear Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        Num = Queue_Front(Queue ,&Status);printf("Status of Queue Front operation = %d \t",Status) ;printf("Front Item = %d \n",*((uint32_t *)Num)) ;
        printf("===================================================\n") ;
        Status = Queue_Display(Queue) ;printf("Status of the Display operation = %d \n",Status) ;
        printf("===================================================\n") ;
    }
    else{
        Status = Queue_Destroy(Queue) ;
        if(!Status){

        }
        else
        {
            printf("Now Destroy it") ;
            for(L_Counter = ZERO ; L_Counter < 13 ; L_Counter++)
            {
                printf(".") ;
                Sleep(250) ;
            }
            printf("\n") ;
            printf("Destroyed is Done :) \t") ;printf("Status of Destroy = %d \n",Status) ;
            return 0 ;
        }
    }

    return 0;
}
