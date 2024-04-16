#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

/**
 * @brief Add New Element in the Begginnig of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
List_Status Insert_Beggining(Node_t **Head ,uint64_t Data){
    List_Status Status = ERROR ;
    Node_t *TempNode = NULL ;
    Node_t *Node = *Head ;

    TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
    if(!TempNode) /*Node Failed to Allocated*/
    {
        Status = ERROR ;
        TempNode = NULL ;
    }
    else/*Node is Successfully Allocated*/
    {
        if(ZERO == GetLength(*Head))/*List is Empty*/
        {
            *Head = TempNode ;
            TempNode->PreviousNode = NULL ;
            TempNode->NextNode = NULL ;
            TempNode->NodeData = Data ;
            Status = NO_ERROR ;
        }
        else/*List is Not Empty*/
        {
            Node->PreviousNode = TempNode ;
            TempNode->PreviousNode = NULL ;
            TempNode->NextNode = Node ;
            *Head = TempNode ;
            TempNode->NodeData = Data ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Add New Element in the End of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
List_Status Insert_End(Node_t **Head ,uint64_t Data){
    List_Status Status = ERROR ;
    Node_t *TempNode = NULL ;
    Node_t *LastNode = *Head ;
    uint32_t NodeCounter = 1 ;

    TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
    if(!TempNode) /*Node Failed to Allocated*/
    {
        Status = ERROR ;
        TempNode = NULL ;
    }
    else/*Node is Successfully Allocated*/
    {
        if(ZERO == GetLength(*Head))/*List is Empty*/
        {
            *Head = TempNode ;
            TempNode->PreviousNode = NULL ;
            TempNode->NextNode = NULL ;
            TempNode->NodeData = Data ;
            Status = NO_ERROR ;
        }
        else/*List is Not Empty*/
        {
            while(NULL != LastNode->NextNode)
            {
                LastNode = LastNode->NextNode ;
            }
            TempNode->NextNode = NULL ;
            TempNode->PreviousNode = LastNode ;
            TempNode->NodeData = Data ;
            LastNode->NextNode = TempNode ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Add New Element After specific element in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @param (Index) the number of the element to insert the (Data After it)
 * @retval Status of the Process
**/
List_Status Insert_After(Node_t *Head ,uint32_t Index ,uint64_t Data){
    List_Status Status = ERROR ;
    Node_t *TempNode = NULL ;
    Node_t *NodePrevious = Head ;
    Node_t *NodeNext = Head ;
    uint32_t NodeCounter1 = 1 ;
    uint32_t NodeCounter2 = 1 ;

    if((Index <= 0) || (Index >= GetLength(Head)))/*Validate the Index that User Send*/
    {
        Status = ERROR ;
        TempNode = NULL ;
    }
    else
    {
        TempNode = (Node_t *)malloc(sizeof(Node_t)) ;
        if(!TempNode) /*Node Failed to Allocated*/
        {
            Status = ERROR ;
            TempNode = NULL ;
        }
        else/*Node is Successfully Allocated*/
        {
            while(NodeCounter1 < Index)
            {
                NodePrevious = NodePrevious->NextNode ;
                NodeCounter1++ ;
            }
            while(NodeCounter2 < (Index+1))
            {
                NodeNext = NodeNext->NextNode ;
                NodeCounter2++ ;
            }
            TempNode->NodeData = Data ;
            TempNode->NextNode = NodeNext ;
            TempNode->PreviousNode = NodePrevious ;
            NodeNext->PreviousNode = TempNode ;
            NodePrevious->NextNode = TempNode ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Delete Element From the Beggining of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @retval Status of the Process
**/
List_Status Delete_Beggining(Node_t **Head){
    List_Status Status = ERROR ;
    Node_t *Node = *Head ;
    Node_t *NodeNext = *Head ;

    if(ZERO == GetLength(*Head))/*List is Empty*/
    {
        Status = ERROR ;
    }
    else/*List is Not Empty*/
    {
        if(1 == GetLength(*Head))/*There is One Element in the List*/
        {
            Node->NextNode = NULL ;
            Node->PreviousNode = NULL ;
            free(Node) ;
            Node = NULL ;
            *Head = NULL ;
            Status = NO_ERROR ;
        }
        else/*There is More than One Element in the List*/
        {
            NodeNext = Node->NextNode ;
            Node->NextNode = NULL ;
            Node->PreviousNode = NULL ;
            free(Node) ;
            Node = NULL ;
            *Head = NodeNext ;
            NodeNext->PreviousNode = NULL ;
            Status = NO_ERROR ;
        }
    }
    return Status ;
}

/**
 * @brief Delete Element From Specific Index in the List
 * @param (Head) Pointer to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @retval Status of the Process
**/
List_Status Delete_Index(Node_t *Head ,uint32_t Index){
    List_Status Status = ERROR ;
    Node_t *Node = Head ;
    Node_t *NodeNext = Head ;
    Node_t *NodePrevious = Head ;
    uint32_t NodeCounter1 = 1 ;
    uint32_t NodeCounter2 = 1 ;
    uint32_t NodeCounter3 = 1 ;

    if((Index <= 1) || (Index > GetLength(Head)))/*Validate the Index that User Send*/
    {
        Status = ERROR ;
    }
    else
    {
        if(1 >= GetLength(Head))/*List is Empty*/
        {
            Status = ERROR ;
        }
        else/*List is Not Empty*/
        {
            if(Index == GetLength(Head))/*Delete Final Element*/
            {
                while(NodeCounter1 < Index-1)
                {
                    NodePrevious = NodePrevious->NextNode ;
                    NodeCounter1++ ;
                }
                while(NodeCounter3 < Index)
                {
                    Node = Node->NextNode ;
                    NodeCounter3++ ;
                }
                NodePrevious->NextNode = NULL ;
                Node->NextNode = NULL ;
                Node->PreviousNode = NULL ;
                free(Node) ;
                Node = NULL ;
                Status = NO_ERROR ;
            }
            else
            {
                if(2 < GetLength(Head))/*More than Two Element in the List*/
                {
                    while(NodeCounter1 < Index-1)
                    {
                        NodePrevious = NodePrevious->NextNode ;
                        NodeCounter1++ ;
                    }
                    while(NodeCounter2 < (Index+1))
                    {
                        NodeNext = NodeNext->NextNode ;
                        NodeCounter2++ ;
                    }
                    while(NodeCounter3 < Index)
                    {
                        Node = Node->NextNode ;
                        NodeCounter3++ ;
                    }
                    NodePrevious->NextNode = NodeNext ;
                    NodeNext->PreviousNode = NodePrevious ;
                    Node->NextNode = NULL ;
                    Node->PreviousNode = NULL ;
                    free(Node) ;
                    Node = NULL ;
                    Status = NO_ERROR ;
                }
                else/*Only Two Element in the List*/
                {
                    while(NodeCounter3 < Index)
                    {
                        Node = Node->NextNode ;
                        NodeCounter3++ ;
                    }
                    while(NodeCounter1 < Index-1)
                    {
                        NodePrevious = NodePrevious->NextNode ;
                        NodeCounter1++ ;
                    }
                    NodePrevious->NextNode = NULL ;
                    Node->NextNode = NULL ;
                    Node->PreviousNode = NULL ;
                    free(Node) ;
                    Node = NULL ;
                    Status = NO_ERROR ;
                }
            }
        }
    }
    return Status ;
}

/**
 * @brief return Element From Specific Index in the List
 * @param (Head) Pointer to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @param (Status) Pointer to return the status of the Process in it
 * @retval Element From Specific Index in the List
**/
uint64_t Retrieve_Data(Node_t *Head ,uint32_t Index ,List_Status *Status)
{
    uint64_t Data = ZERO_INIT ;
    Node_t *Node = Head ;
    uint32_t NodeCounter = 1 ;

    if(NULL == Status){/*Nothing*/}
    else
    {
        if((Index < 1) || (Index > GetLength(Head)))/*Validate the Index that User Send*/
        {
            *Status = ERROR ;
        }
        else
        {
            if(1 > GetLength(Head))/*List is Empty*/
            {
                *Status = ERROR ;
            }
            else/*List is Not Empty*/
            {
                while(NodeCounter < Index)
                {
                    Node = Node->NextNode ;
                    NodeCounter++ ;
                }
                Data = Node->NodeData ;
                *Status = NO_ERROR ;
            }
        }
    }
    return Data ;
}

/**
 * @brief Display The Data in List in the Memory from start to end
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Forward_Data(Node_t *Head ){
    List_Status Status = NO_ERROR ;
    Node_t *TempNode = Head ;
    if(GetLength(Head))
    {
        while(NULL != TempNode)
        {
            printf("%d >> ",TempNode->NodeData) ;
            TempNode = TempNode->NextNode ;
        }
        printf("END \n") ;
    }
    else
    {
        printf("List is Empty :) \n");
    }
    return Status ;
}

/**
 * @brief Display The Data in List in the Memory from end to start
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Back_Data(Node_t *Head ){
    List_Status Status = NO_ERROR ;
    Node_t *LastNode = Head ;
    if(GetLength(Head)){
        while(NULL != LastNode->NextNode)
        {
            LastNode = LastNode->NextNode ;
        }
        while(NULL != LastNode)
        {
            printf("%d >> ",LastNode->NodeData) ;
            LastNode = LastNode->PreviousNode ;
        }
        printf("END \n") ;
    }
    else
    {
        printf("List is Empty :) \n");
    }
    return Status ;
}

/**
 * @brief Display The Addressies of the Data in List in the Memory from start to end
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Forward_Addressies(Node_t *Head){
    List_Status Status = NO_ERROR ;
    Node_t *TempNode = Head ;
    if(GetLength(Head))
    {
        while(NULL != TempNode)
        {
            printf("0x%X >> ",TempNode) ;
            TempNode = TempNode->NextNode ;
        }
        printf("NULL \n") ;
    }
    else
    {
        printf("List is Empty :) \n");
    }
    return Status ;
}

/**
 * @brief Display The Addressies of the Data in List in the Memory from end to start
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Back_Addressies(Node_t *Head){
    List_Status Status = NO_ERROR ;
    Node_t *LastNode = Head ;
    if(GetLength(Head))
    {
        while(NULL != LastNode->NextNode)
        {
            LastNode = LastNode->NextNode ;
        }
        while(NULL != LastNode)
        {
            printf("0x%X >> ",LastNode) ;
            LastNode = LastNode->PreviousNode ;
        }
        printf("NULL \n") ;
    }
    else
    {
        printf("List is Empty :) \n");
    }
    return Status ;
}

/**
 * @brief return the Number of the Element in the List
 * @param (Head) Pointer to the ListHead
 * @retval the Number of the Element in the List
**/
uint32_t GetLength(Node_t *Head){
    uint32_t Len = ZERO_INIT ;
    Node_t *TempNode = Head ;
    while(NULL != TempNode)
    {
        TempNode = TempNode->NextNode ;
        Len++ ;
    }
    return Len ;
}
