// ow_data.h //
//
// data structures
//
// 25NOV2025 - Started
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Changes 
//
// AMD001: 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef OW_DATA_H
#define OW_DATA_H

// STRUCT DECLARATIONS -----------------------------------------------------------------------------------------------
// NOTE!! - declare here, but define in the .c file
//        - this creates 'opaque' structs, meaning external code cannot reference internals of them
//        - external code can only access them through the functions declared here

// LINKED LISTS /////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ll_Node ll_Node;
typedef struct linkedList linkedList;


// ---------------------------------------------------------------------------------------------------------------


//FUNCTIONS////////////////////////////////////////////////////////////////////////////////////////////////////////

// LINKED LIST FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////
// Create empty linked list, return pointer to it
linkedList* ll_Init();

// Print the details in this linked list
void ll_diagnostic(linkedList *input);

// Print the details of given node
void ll_node_diagnostic(ll_Node *input);

// return pointer to the head node
ll_Node* ll_getHead(linkedList *list);

// return pointer to the Tail node
ll_Node* ll_getTail(linkedList *list);

// Return pointer to next node
ll_Node* ll_getNext(ll_Node *node);

// Return pointer to previous node
ll_Node* ll_getPrev(ll_Node *node);

// add a node to linked list
void ll_addNode(linkedList *list, void *data, size_t size);

// Insert a new node before the given one
void ll_insertBefore(linkedList *list, ll_Node *node, void *data, size_t size);

// Insert a new node after the given one
void ll_insertAfter(linkedList *list, ll_Node *node, void *data, size_t size);

// Insert a node before the given one
void ll_insertBefore(linkedList *list, ll_Node *node, void *data, size_t size);

// Remove a node from the linked list
void ll_removeNode(linkedList *list, ll_Node *node);

// Remove node before the given one
void ll_removeBefore(linkedList *list, ll_Node *node);

// Remove node after the given one
void ll_removeAfter(linkedList *list, ll_Node *node);

// Remove all nodes from the linked list
void ll_destroyList(linkedList *list);

// Return void pointer to the data of Node
// NOTE: end user is responsible for handling types
//     : cast the void pointer to pointer of correct type and dereference eg;
//     : data = *(type*)returned_pointer;
void* ll_getData(ll_Node *node);

// Change data of an existing node
void ll_changeData(ll_Node *node, void *data, size_t size);

#endif