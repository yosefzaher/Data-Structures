#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

#include "DataType.h"

#define ZERO 0
#define ZERO_INIT 0

#define NULL_ERROR -1
#define ERROR 0
#define NO_ERROR 1


typedef struct Node{
    uint64_t Data_Field ;
    struct Node *Link_Field ;
}Node_t ;


/**
 * @brief Add New Element in the Begginnig of the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
int32_t Insert_At_Beggining(Node_t **ListHead ,uint64_t Data) ;

/**
 * @brief Add New Element in the End of the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @retval Status of the Process
**/
int32_t Insert_At_end(Node_t **ListHead ,uint64_t Data) ;

/**
 * @brief Add New Element After specific element in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Data) the Data to be added to the List
 * @param (Index) the number of the element to insert the (Data After it)
 * @retval Status of the Process
**/
int32_t Insert_After(Node_t *ListHead ,uint8_t Index ,uint64_t Data) ;

/**
 * @brief Delete Element From Specific Index in the List
 * @param (ListHead) Double Pointer to be refrence to the ListHead
 * @param (Index) Index of the Element that will be removed from the List
 * @retval Status of the Process
**/
int32_t Delete_Index(Node_t **ListHead ,uint8_t Index) ;

/**
 * @brief Display The Data in List in the Memory
 * @param (ListHead) Pointer to the ListHead
 * @retval Status of the Process
**/
int32_t Display_Data(Node_t *ListHead) ;

/**
 * @brief Display The Addressies of the Data in List in the Memory
 * @param (ListHead) Pointer to the ListHead
 * @retval Status of the Process
**/
int32_t Display_Addressies(Node_t *ListHead) ;

/**
 * @brief return the Number of the Element in the List
 * @param (ListHead) Pointer to the ListHead
 * @param (Status) Pointer point to the Status of the Process
 * @retval Status of the Process
**/
int32_t GetLength(Node_t *ListHead ,boolean_t *Status) ;

/**
 * @brief return the Element in the index that user send
 * @param (Status) Pointer point to the Status of the Process
 * @param (ListHead) Pointer to the ListHead
 * @param (Index) Index of the Element that will be returned from the List
 * @retval return the Number in the index that user send
**/
uint64_t Retrieve_Data(Node_t *ListHead ,uint8_t Index ,int32_t *Status) ;


#endif // _SINGLELINKEDLIST_H_
