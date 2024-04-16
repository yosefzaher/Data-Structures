#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "DynamicStack.h"

Stack_DyDs_t *Stack = NULL ;
Stack_Status_t Status = Stack_Nok ;
uint32_t Max = 0 ;
uint32_t Counter = ZERO_INIT ;
boolean_t Check = ZERO_INIT ;
uint16_t L_Counter = ZERO_INIT ;
int32_t Num = ZERO_INIT ;

int main()
{
    void *Num   ;
    uint32_t Num0 = 0 ;
    uint32_t Num1 = 1 ;
    uint32_t Num2 = 2 ;
    uint32_t Num3 = 3 ;
    uint32_t Num4 = 4 ;
    uint32_t Num5 = 5 ;
    uint32_t Num6 = 6 ;
    uint32_t Num7 = 7 ;
    printf("Enter the Max Number of Element you want :  ") ;
    scanf("%d",&Max) ;

    Stack = Stack_Creat(Max ,&Status) ;
    if(!Stack)
    {
        printf("Stack Can't Be Created :( \n") ;
        printf("Status = %d \n",Status);
    }
    else
    {
        printf("Stack Created Of (%d) Element Created Successflly :) \n",Max) ;
        printf("Status = %d \n",Status);
        printf("Now ,You want to destroy it or not :  ") ;
        scanf("%d",&Check) ;
        if(Check == Stack_Nok){

        }
        else{
            printf("Okay ,Now destroy it") ;
            for(Counter = ZERO ; Counter < 13 ;Counter++)
            {
                printf(".") ;
                Sleep(250) ;
            }
            printf("\n") ;
            Stack = Stack_Destroy(Stack ,&Status) ;
            if(!Stack)
            {
                printf("Destroyed Successfully :) \n") ;
                printf("Status = %d \n",Status) ;
                return 0;
            }
            else
            {
                printf("Destroyed Failled :( \n") ;
                printf("Status = %d \n",Status) ;
            }
        }
        printf("================================================================================================ \n") ;
        Status = Stack_Push(Stack ,&Num0) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num1) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num2) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num3) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num4) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num5) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num6) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num7) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num0) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num1) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num2) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num3) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num4) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num5) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num6) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num7) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num0) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num1) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num2) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num3) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num4) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num5) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num6) ;printf("Status = %d \n",Status);
        Status = Stack_Push(Stack ,&Num7) ;printf("Status = %d \n",Status);

        printf("================================================================================================ \n") ;
        Status = Stack_Size(Stack ,&Num0) ;printf("Status = %d \n",Status); printf("Size = %d \n",Num0) ;
        printf("================================================================================================ \n") ;
        Status = Stack_Display(Stack) ;printf("Status = %d \n",Status);
        printf("================================================================================================ \n");
        printf("Stack Top = %d \n",Stack->Stack_Top) ;
        printf("Element Counter = %d \n",Stack->Element_Counter) ;
        printf("Max Size = %d \n",Stack->Max_Size) ;
        printf("================================================================================================ \n");
        Num = Stack_Peek(Stack ,&Status) ;printf("Status = %d \n",Status); printf("Stack Top = %d \n",*((uint32_t *)Num)) ;
        printf("================================================================================================ \n");
        printf("Stack Top = %d \n",Stack->Stack_Top) ;
        printf("Element Counter = %d \n",Stack->Element_Counter) ;
        printf("Max Size = %d \n",Stack->Max_Size) ;
        printf("================================================================================================ \n");
        Num = Stack_Pop(Stack ,&Status) ;printf("Status = %d \n",Status); printf("Stack Top = %d \n",*((uint32_t *)Num)) ;
        printf("================================================================================================ \n");
        printf("Stack Top = %d \n",Stack->Stack_Top) ;
        printf("Element Counter = %d \n",Stack->Element_Counter) ;
        printf("Max Size = %d \n",Stack->Max_Size) ;
        printf("================================================================================================ \n");


    }

    return 0;
}
