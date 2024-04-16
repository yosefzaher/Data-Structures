#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include "DataType.h"

#define ZERO_INIT 0
#define ZERO 0

typedef struct Node{
    uint64_t NodeData ;
    struct Node *NextNode ;
    struct Node *PreviousNode ;
}Node_t ;

typedef enum{
    ERROR = 0 ,
    NO_ERROR
}List_Status ;


/**
 * @brief Add New Element in the Begginnig of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
List_Status Insert_Beggining(Node_t **Head ,uint64_t Data) ;

/**
 * @brief Add New Element in the End of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
List_Status Insert_End(Node_t **Head ,uint64_t Data) ;

/**
 * @brief Add New Element After specific element in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @param (Index) the number of the element to insert the (Data After it)
 * @retval Status of the Process
**/
List_Status Insert_After(Node_t *Head ,uint32_t Index ,uint64_t Data) ;

/**
 * @brief Delete Element From Specific Index in the List
 * @param (Head) Pointer to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @retval Status of the Process
**/
List_Status Delete_Index(Node_t *Head ,uint32_t Index) ;

/**
 * @brief Delete Element From the Beggining of the List
 * @param (Head) Double Pointer to be refrence to the ListHead
 * @retval Status of the Process
**/
List_Status Delete_Beggining(Node_t **Head) ;

/**
 * @brief return Element From Specific Index in the List
 * @param (Head) Pointer to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @param (Status) Pointer to return the status of the Process in it
 * @retval Element From Specific Index in the List
**/
uint64_t Retrieve_Data(Node_t *Head ,uint32_t Index ,List_Status *Status) ;

/**
 * @brief Display The Data in List in the Memory from start to end
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Forward_Data(Node_t *Head) ;

/**
 * @brief Display The Data in List in the Memory from end to start
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Back_Data(Node_t *Head ) ;

/**
 * @brief Display The Addressies of the Data in List in the Memory from start to end
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Forward_Addressies(Node_t *Head) ;

/**
 * @brief Display The Addressies of the Data in List in the Memory from end to start
 * @param (Head) Pointer to the ListHead
 * @retval Status of the Process
**/
List_Status Display_Back_Addressies(Node_t *Head) ;

/**
 * @brief return the Number of the Element in the List
 * @param (Head) Pointer to the ListHead
 * @retval the Number of the Element in the List
**/
uint32_t GetLength(Node_t *Head) ;


#endif // _DOUBLELINKEDLIST_H_
