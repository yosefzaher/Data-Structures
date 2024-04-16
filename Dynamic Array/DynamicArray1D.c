#include <stdio.h>
#include <stdlib.h>
#include "Platform_Type.h"

uint32 *Ptr = NULL ;
uint32 number_of_element = 0 ;
uint32 Counter = 0 ;
uint32 Counter2 = 0 ;

int main(){
    printf("Enter the number of element you want : ") ;
    scanf("%d",&number_of_element) ;

    Ptr = (uint32 *)calloc(number_of_element ,sizeof(uint32)) ;
    if(NULL != Ptr){
        for(Counter = 0 ; Counter < number_of_element ; ++Counter)
        {
            printf("Enter element number %i :  ",(Counter+1)) ;
            scanf("%d",&Ptr[Counter]) ;
        }
        printf("Do you want to show data(1) or add data(2) : ");
        scanf("%d",&Counter) ;
        if(1 == Counter){
            for(Counter = 0 ; Counter < number_of_element ; ++Counter)
            {
                printf("Ptr[%i] = %i\n",Counter,Ptr[Counter]) ;
            }
        }
        else if(2 == Counter)
        {
            printf("Enter the number of element you want to add :  ");
            scanf("%d",&Counter2) ;
            Ptr = (uint32 *)realloc(Ptr,((number_of_element + Counter2)*sizeof(uint32))) ;
            if(NULL != Ptr){
                for(Counter = (number_of_element) ; Counter < (number_of_element+Counter2) ; ++Counter)
                {
                    printf("Enter element number %i :  ",(Counter+1)) ;
                    scanf("%d",&Ptr[Counter]) ;
                }
                for(Counter = 0 ; Counter < number_of_element+Counter2 ; ++Counter)
                {
                    printf("Ptr[%i] = %i\n",Counter,Ptr[Counter]) ;
                }

            }
            else{
                printf("Error!!!\n") ;
            }
        }

        free(Ptr) ;
    }
    else{
        printf("Error! ,Could't allocate the size you want \n") ;
    }


    return 0 ;
}



