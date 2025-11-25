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

// DATA STRUCTURES -----------------------------------------------------------------------------------------------
// Linked List

typedef struct ll_Node
{
    struct ll_Node *prev_node;
    struct ll_Node *next_node;
    
    size_t size;
    void *data;
}
ll_Node;

typedef struct linkedList
{
	ll_Node *head_node;
    ll_Node *tail_node;
    int node_count;
    size_t size;
}
linkedList;

// ---------------------------------------------------------------------------------------------------------------


//FUNCTIONS////////////////////////////////////////////////////////////////////////////////////////////////////////

// Create empty linked list
linkedList ll_Init();

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

// Remove a node from the linked list
void ll_removeNode(linkedList *list, ll_Node *node);

// Remove all nodes from the linked list
void ll_destroyList(linkedList *list);

#endif