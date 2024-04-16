#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

/**
 * @brief Add New Element in the Begginnig of the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
int32_t Insert_At_Beggining(Node_t **ListHead ,uint64_t Data){
    int32_t Status = ERROR ;
    Node_t *TempNode = *ListHead ;
    TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
    if(NULL == TempNode)
    {
        Status = ERROR ;
    }
    else
    {
        if(NULL == ListHead)
        {
            *ListHead = TempNode ;
            TempNode->Data_Field = Data ;
            TempNode->Link_Field = NULL ;
            Status = NO_ERROR ;
        }
        else
        {
            TempNode->Link_Field = *ListHead ;
            TempNode->Data_Field = Data ;
            *ListHead = TempNode ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Add New Element in the End of the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
int32_t Insert_At_end(Node_t **ListHead ,uint64_t Data){
    int32_t Status = ERROR ;
    Node_t *TempNode = NULL  ;
    Node_t *LastNode = *ListHead  ;
    TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
    if(NULL == TempNode)
    {
        Status = ERROR ;
    }
    else
    {
        if(NULL == *ListHead)
        {
            *ListHead = TempNode ;
            TempNode->Data_Field = Data ;
            Status = NO_ERROR ;
        }
        else
        {
            while(NULL != LastNode->Link_Field)
            {
                LastNode = LastNode->Link_Field ;
            }
            LastNode->Link_Field = TempNode ;
            TempNode->Data_Field = Data ;
            TempNode->Link_Field = NULL ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Add New Element After specific element in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
int32_t Insert_After(Node_t *ListHead ,uint8_t Index ,uint64_t Data){
    int32_t Status = ERROR ;
    uint32_t NodeCounter = 1 ;
    Node_t *TempNode = NULL ;
    Node_t *Node = ListHead ;
    if((Index <= ZERO) || (Index >= GetLength(ListHead,&Status)))
    {
        Status = ERROR ;
        printf("Invalid Index !\n") ;
    }
    else
    {
        TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
        if(!TempNode)
        {
            Status = ERROR ;
        }
        else
        {
            while(NodeCounter < Index)
            {
                Node = Node->Link_Field ;
                NodeCounter++ ;
            }
            TempNode->Link_Field = Node->Link_Field ;
            Node->Link_Field = TempNode ;
            TempNode->Data_Field = Data ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Delete Element From Specific Index in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @retval Status of the Process
**/
int32_t Delete_Index(Node_t **ListHead ,uint8_t Index)
{
    int32_t Status = ERROR ;
    Node_t *Node1 = *ListHead ;
    Node_t *Node2 = *ListHead ;
    uint32_t NodeCounter = 1 ;
    if(NULL == *ListHead)
    {
       Status = ERROR ;
       printf("List is Empty ! \n") ;
    }
    else if((Index <= ZERO) || (Index > GetLength(*ListHead ,&Status)))
    {
        Status = ERROR ;
        printf("Invalid Index ! \n") ;
    }
    else
    {
        if((1 == GetLength(*ListHead ,&Status)) && (1 == Index))
        {
            *ListHead = NULL ;
            Node1->Link_Field = NULL ;
            free(Node1) ;
            Node1 = NULL ;
        }
        else if((1 < GetLength(*ListHead ,&Status)) && (1 == Index))
        {
            *ListHead = Node1->Link_Field ;
            Node1->Link_Field = NULL ;
            free(Node1) ;
            Node1 = NULL ;
        }
        else
        {
            while(NodeCounter < Index)
            {
                Node1 = Node2 ;
                Node2 = Node2->Link_Field ;
                NodeCounter++ ;
            }
            Node1->Link_Field = Node2->Link_Field ;
            Node2->Link_Field = NULL ;
            free(Node2) ;
            Node2 = NULL ;
        }
    }
    return Status ;
}

/**
 * @brief return the Element in the index that user send
 * @param (Status) Pointer point to the Status of the Process
 * @param (ListHead) Pointer to the ListHead
 * @param (Index) Index of the Element that will be returned from the List
 * @retval return the Number in the index that user send
**/
uint64_t Retrieve_Data(Node_t *ListHead ,uint8_t Index ,int32_t *Status)
{
    Node_t *Node = ListHead ;
    uint32_t NodeCounter = 1 ;
    uint64_t Data = ZERO ;
    if(NULL == Status)
    {
        Status = NULL ;
    }
    if((Index <= ZERO) || (Index > GetLength(ListHead ,Status)))
    {
        *Status = ERROR ;
    }
    else
    {
        while(NodeCounter < Index)
        {
            Node = Node->Link_Field ;
            NodeCounter++ ;
        }
        Data = Node->Data_Field ;
        *Status = NO_ERROR ;
    }
    return Data ;
}

/**
 * @brief Display The Data in List in the Memory
 * @param (ListHead) Pointer to the ListHead
 * @retval Status of the Process
**/
int32_t Display_Data(Node_t *ListHead){
    int32_t Status = NO_ERROR ;
    Node_t *TempNode = ListHead ;
    while(NULL != TempNode)
    {
        printf("%d >> ",TempNode->Data_Field) ;
        TempNode = TempNode->Link_Field ;
    }
    printf("The End\n") ;
    return Status ;
}

/**
 * @brief Display The Addressies of the Data in List in the Memory
 * @param (ListHead) Pointer to the ListHead
 * @retval Status of the Process
**/
int32_t Display_Addressies(Node_t *ListHead){
    int32_t Status = NO_ERROR ;
    Node_t *TempNode = ListHead ;
    while(NULL != TempNode)
    {
        printf("0x%X >> ",TempNode) ;
        TempNode = TempNode->Link_Field ;
    }
    printf("NULL\n") ;
    return Status ;
}

/**
 * @brief return the Number of the Element in the List
 * @param (ListHead) Pointer to the ListHead
 * @param (Status) Pointer point to the Status of the Process
 * @retval Status of the Process
**/
int32_t GetLength(Node_t *ListHead ,boolean_t *Status){
    int32_t Length = ZERO_INIT ;
    Node_t *TempNode = ListHead ;
    if(NULL == Status)
    {
        Status = NULL;
        Length = NULL_ERROR ;
    }
    else
    {
        while(NULL != TempNode)
        {
            Length++ ;
            TempNode = TempNode->Link_Field ;
        }
        *Status = NO_ERROR ;
    }
    return Length ;
}


















