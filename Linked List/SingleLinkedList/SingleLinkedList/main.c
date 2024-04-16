#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

Node_t *List = NULL ;
int32_t Status = ZERO_INIT;
int32_t Length = ZERO_INIT;

uint64_t Data1 = 12 ;
uint64_t Data2 = 14 ;
uint64_t Data3 = 15 ;
uint64_t Data4 = 16 ;
uint64_t Data5 = 127 ;
uint64_t Data6 = 189 ;
uint64_t Data7 = 1157 ;
uint64_t Data8 = 111 ;
uint64_t Data9 = 93 ;
uint64_t Data10 = 255 ;
uint64_t Data11 = 256 ;
uint64_t Data12 = 257 ;

int main()
{
    Status = Insert_At_Beggining(&List ,Data1) ;printf("The Data insertion in list = %d \t",Data1);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data2) ;printf("The Data insertion in list = %d \t",Data2);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data3) ;printf("The Data insertion in list = %d \t",Data3);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data4) ;printf("The Data insertion in list = %d \t",Data4);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data5) ;printf("The Data insertion in list = %d \t",Data5);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data6) ;printf("The Data insertion in list = %d \t",Data6);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data7) ;printf("The Data insertion in list = %d \t",Data7);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data8) ;printf("The Data insertion in list = %d \t",Data8);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_Beggining(&List ,Data9) ;printf("The Data insertion in list = %d \t",Data9);printf("Status of the Data Insertion = %d \n",Status) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Data = %d \n",Status) ;
    Status = Display_Data(List) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Addressies = %d \n",Status) ;
    Status = Display_Addressies(List) ;
    printf("=======================================================================\n") ;
    Length = GetLength(List,&Status) ;printf("The length of the List = %d \t",Length);printf("Status of the GetLength = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Status = Insert_At_end(&List ,Data7) ;printf("The Data insertion in list = %d \t",Data7);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_end(&List ,Data8) ;printf("The Data insertion in list = %d \t",Data8);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_At_end(&List ,Data9) ;printf("The Data insertion in list = %d \t",Data9);printf("Status of the Data Insertion = %d \n",Status) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Data = %d \n",Status) ;
    Status = Display_Data(List) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Addressies = %d \n",Status) ;
    Status = Display_Addressies(List) ;
    printf("=======================================================================\n") ;
    Length = GetLength(List,&Status) ;printf("The length of the List = %d \t",Length);printf("Status of the GetLength = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Status = Insert_After(List ,2 ,Data10) ;printf("The Data insertion in list = %d \t",Data10);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_After(List ,6 ,Data11) ;printf("The Data insertion in list = %d \t",Data11);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_After(List ,9 ,Data12) ;printf("The Data insertion in list = %d \t",Data12);printf("Status of the Data Insertion = %d \n",Status) ;
    Status = Insert_After(List ,0 ,Data12) ;printf("The Data insertion in list = %d \t",Data12);printf("Status of the Data Insertion = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Status = Display_Data(List) ;
    printf("Status of Display Data = %d \n",Status) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Addressies = %d \n",Status) ;
    Status = Display_Addressies(List) ;
    printf("=======================================================================\n") ;
    Length = GetLength(List,&Status) ;printf("The length of the List = %d \t",Length);printf("Status of the GetLength = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Data10 = Retrieve_Data(List ,5 ,&Status) ;printf("Data Retrieved from Index %d = %d \t",5,Data10) ;printf("Status of Retrieving Data = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Status = Delete_Index(&List ,15) ;printf("The Data Deleted in list in index = %d \t",15);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,14) ;printf("The Data Deleted in list in index = %d \t",14);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,13) ;printf("The Data Deleted in list in index = %d \t",13);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,12) ;printf("The Data Deleted in list in index = %d \t",12);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,11) ;printf("The Data Deleted in list in index = %d \t",11);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,10) ;printf("The Data Deleted in list in index = %d \t",10);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,9) ;printf("The Data Deleted in list in index = %d \t",9);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,8) ;printf("The Data Deleted in list in index = %d \t",8);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,7) ;printf("The Data Deleted in list in index = %d \t",7);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,6) ;printf("The Data Deleted in list in index = %d \t",6);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,5) ;printf("The Data Deleted in list in index = %d \t",5);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,4) ;printf("The Data Deleted in list in index = %d \t",4);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,3) ;printf("The Data Deleted in list in index = %d \t",3);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,2) ;printf("The Data Deleted in list in index = %d \t",2);printf("Status of the Data Deletion = %d \n",Status) ;
    Status = Delete_Index(&List ,1) ;printf("The Data Deleted in list in index = %d \t",1);printf("Status of the Data Deletion = %d \n",Status) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Data = %d \n",Status) ;
    Status = Display_Data(List) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Addressies = %d \n",Status) ;
    Status = Display_Addressies(List) ;
    printf("=======================================================================\n") ;
    Length = GetLength(List,&Status) ;printf("The length of the List = %d \t",Length);printf("Status of the GetLength = %d \n",Status) ;
    printf("=======================================================================\n") ;
    Status = Insert_At_Beggining(&List ,Data9) ;printf("The Data insertion in list = %d \t",Data9);printf("Status of the Data Insertion = %d \n",Status) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Data = %d \n",Status) ;
    Status = Display_Data(List) ;
    printf("=======================================================================\n") ;
    printf("Status of Display Addressies = %d \n",Status) ;
    Status = Display_Addressies(List) ;
    printf("=======================================================================\n") ;
    Length = GetLength(List,&Status) ;printf("The length of the List = %d \t",Length);printf("Status of the GetLength = %d \n",Status) ;
    printf("=======================================================================\n") ;
    return 0;
}












