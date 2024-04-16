#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "QueueDS.h"

Queue_t *My_Queue = NULL ;
Return_Status Status = QUEUE_NOK ;
uint32_t MaxSize = ZERO_INIT ;
uint32_t L_Counter = ZERO_INIT ;
Boolean_Value Check = False ;
uint32_t Queue_Len = ZERO_INIT ;
void *Item = NULL ;

uint32_t Num1 = 10 ;
uint32_t Num2 = 20 ;
uint32_t Num3 = 30 ;
uint32_t Num4 = 40 ;
uint32_t Num5 = 50 ;
uint32_t Num6 = 60 ;
uint32_t Num7 = 70 ;
uint32_t Num8 = 80 ;
uint32_t Num9 = 90 ;
uint32_t Num10 = 100 ;

uint8_t Alphabet1 = 'a' ;
uint8_t Alphabet2 = 'b' ;

float32_t F1 = 23.5774 ;
float32_t F2 = 65.239563 ;

int main()
{
    printf("Please Enter The Max Size Of The Queue :  ") ;
    scanf("%d",&MaxSize) ;
    My_Queue = Queue_Create(&Status ,&MaxSize) ;
    if(!My_Queue)
    {
        printf("Failled To Create Queue :( \n") ;
        printf("Status of Create Queue = %d \n",Status) ;
    }
    else
    {
        printf("Queue Now is Created Successfully :) \n") ;
        printf("Status of Create Queue = %d \n",Status) ;

        printf("Do You Want To Destroy the Queue From the heap :  ");
        scanf("%d",&Check) ;
        if(!Check)
        {
            printf("Queue Rear = %d \t",My_Queue->Queue_Rear) ;printf("Queue Front = %d \n",(My_Queue->Queue_Front)) ;
            printf("Number of Element in the Queue = %d \n",My_Queue->StackIn->Element_Counter) ;
            Status = Queue_Length(My_Queue,&Queue_Len) ;printf("Length of the Queue = %d \t",Queue_Len) ;printf("Status of Queue Length = %d \n",Status) ;
            printf("===================================================================================================\n");
            Status = Enqueue(My_Queue,&Num1) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num2) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num3) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num4) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num5) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num6) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num7) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num8) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num9) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Num10) ;printf("Status of Enqueue operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            printf("in SatckIn -> Element Counter = %d \t",My_Queue->StackIn->Element_Counter) ;
            printf("in SatckIn -> Max Size = %d \n",(My_Queue->StackIn->Max_Size)) ;
            printf("------------------------------------\n") ;
            for(L_Counter = ZERO ; L_Counter <= (My_Queue->StackIn->Stack_Top) ; L_Counter++)
            {
                printf("Queue[%d] = %d \n",L_Counter,*((uint32_t *)(My_Queue->StackIn->Stack_Pointer[(My_Queue->StackIn->Stack_Top) - L_Counter]))) ;
            }
            printf("Queue Rear = %d \n",My_Queue->Queue_Rear) ;
            Item = Rear_Queue(My_Queue ,&Status) ;
            printf("Queue Rear Element = %d \t",*((uint32_t *)Item)) ;printf("Status of the Rear Queue Operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            printf("===================================================================================================\n");
            Item = Dequeue(My_Queue,&Status) ;printf("Dequeued Element = %d \t",*((uint32_t *)Item));printf("Status of Dequeue operation = %d \n",Status) ;
            Item = Dequeue(My_Queue,&Status) ;printf("Dequeued Element = %d \t",*((uint32_t *)Item));printf("Status of Dequeue operation = %d \n",Status) ;
            Item = Dequeue(My_Queue,&Status) ;printf("Dequeued Element = %d \t",*((uint32_t *)Item));printf("Status of Dequeue operation = %d \n",Status) ;
            Item = Dequeue(My_Queue,&Status) ;printf("Dequeued Element = %d \t",*((uint32_t *)Item));printf("Status of Dequeue operation = %d \n",Status) ;
            printf("===================================================================================================\n");
            printf("------------------------------------\n") ;
            printf("Queue Front = %d \n",My_Queue->Queue_Front) ;
            Item = Front_Queue(My_Queue ,&Status) ;
            printf("Queue Front Element = %d \t",*((uint32_t *)Item)) ;printf("Status of the Rear Queue Operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            printf("Queue Rear = %d \n",My_Queue->Queue_Rear) ;
            Item = Rear_Queue(My_Queue ,&Status) ;
            printf("Queue Rear Element = %d \t",*((uint32_t *)Item)) ;printf("Status of the Rear Queue Operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            Status = Queue_Length(My_Queue,&Queue_Len) ;printf("Queue Length = %d \t",Queue_Len);printf("Status of the Len Queue Operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            Status = Enqueue(My_Queue,&Alphabet1) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&Alphabet2) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&F1) ;printf("Status of Enqueue operation = %d \n",Status) ;
            Status = Enqueue(My_Queue,&F2) ;printf("Status of Enqueue operation = %d \n",Status) ;
            printf("------------------------------------\n") ;
            for(L_Counter = ZERO ; L_Counter <= (My_Queue->StackIn->Stack_Top) ; L_Counter++)
            {
                printf("Queue[%d] = %f \n",L_Counter,*((float32_t *)(My_Queue->StackIn->Stack_Pointer[(My_Queue->StackIn->Stack_Top) - L_Counter]))) ;
            }
        }
        else
        {
            Status = Queue_Destroy(My_Queue) ;
            if(!Status)
            {
                printf("Can't Destroy the Queue :( \n") ;
                printf("The Status of Destroy Queue = %d \n",Status) ;
            }
            else
            {
                printf("Now Destroy it") ;
                for(L_Counter = ZERO ;L_Counter < 13 ; L_Counter++)
                {
                    printf(".") ;
                    Sleep(250) ;
                }
                printf("\n") ;
                printf("The Queue Destroyed Successfully :) \t") ;
                printf("The Status of Destroy Queue = %d \n",Status) ;
            }
            return 0 ;
        }
    }

    return 0;
}
