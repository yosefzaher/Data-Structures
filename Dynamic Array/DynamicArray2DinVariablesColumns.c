#include <stdio.h>
#include <stdlib.h>
#include "Platform_Type.h"

uint32 **Ptr = NULL ;
uint32 number_of_1D_element = 0 ;
uint32 number_of_2D_element = 0 ;
uint32 Counter1 = 0 ;
uint32 Counter2 = 0 ;
uint32 Arr_number_of_2D_element[] ;

int main(){
    printf("Enter the number of rows in 2D Array: ");
    scanf("%d", &number_of_1D_element);
    Ptr = (uint32 **)calloc(number_of_1D_element, sizeof(uint32 *));


    for (Counter1 = 0; Counter1 < number_of_1D_element; ++Counter1) {
        printf("Enter the number of cloumns in row %d  :   ",Counter1) ;
        scanf("%d",&Arr_number_of_2D_element[Counter1]) ;
    }

    for (Counter1 = 0; Counter1 < number_of_1D_element; ++Counter1) {

        Ptr[Counter1] = (uint32 *)calloc(Arr_number_of_2D_element[Counter1], sizeof(uint32));
    }

    for(Counter1 = 0 ;Counter1 < number_of_1D_element ;++Counter1){
        for(Counter2 = 0 ; Counter2 < Arr_number_of_2D_element[Counter1] ;++Counter2)
        {
            printf("Ptr[%i][%i] = ",Counter1,Counter2) ;
            scanf("%d",&(Ptr[Counter1][Counter2])) ;
        }
    }
    printf("=====================================================================\n") ;
    for(Counter1 = 0 ;Counter1 < number_of_1D_element ;++Counter1){
        for(Counter2 = 0 ; Counter2 < Arr_number_of_2D_element[Counter1] ;++Counter2)
        {
            printf("Ptr[%i][%i] = %i \t",Counter1,Counter2,Ptr[Counter1][Counter2]) ;
        }
        printf("\n") ;
    }
    for(Counter1 = 0 ; Counter1 < number_of_1D_element ; ++Counter1)
    {
        free(Ptr[Counter1]) ;
    }
    free(Ptr) ;
    printf("=====================================================================\n") ;
    printf("Free is Done:)\n");

    return 0 ;
}



