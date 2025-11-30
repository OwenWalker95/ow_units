// ow_data.c //
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ow_data.h"

//STRUCT DEFINITIONS/////////////////////////////////////////////////////////////////////////////////////
// LINKED LISTS /////////////////////////////////////////////////////////////////////////////////////////
struct ll_Node
{
    struct ll_Node *prev_node;
    struct ll_Node *next_node;
    
    size_t size;
    void *data;
};

struct linkedList
{
	ll_Node *head_node;
    ll_Node *tail_node;
    int node_count;
    size_t size;
};

//FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////
//LINKED LISTS///////////////////////////////////////////////////////////////////////////////////////////
linkedList* ll_Init(){
    linkedList *new_ll = malloc(sizeof(linkedList));

    new_ll->head_node = NULL;
    new_ll->tail_node = NULL;
    new_ll->node_count = 0;
    new_ll->size = 0;

    return new_ll;
}

void ll_diagnostic(input)
linkedList *input;{
    printf("HeadNode : %p\n", input->head_node);
    printf("TailNode : %p\n", input->tail_node);
    printf("NodeCount: %d\n", input->node_count);
    printf("ListSize : %zu\n", input->size);    
}

void ll_node_diagnostic(input)
ll_Node *input;{
    printf("PrevNode    : %p\n", input->prev_node);
    printf("NextNode    : %p\n", input->next_node);
    printf("DataLocation: %p\n", input->data);
    printf("DataSize    : %zu\n", input->size);
}

ll_Node* ll_getHead(list)
linkedList *list;{
    return list->head_node;
}

ll_Node* ll_getTail(list)
linkedList *list;{
    return list->tail_node;
}

ll_Node* ll_getNext(node)
ll_Node *node;{
    return node->next_node;
}

ll_Node* ll_getPrev(node)
ll_Node *node;{
    return node->prev_node;
}

void ll_addNode(list, data, size)
linkedList *list;
void *data;
size_t size;{
    // create the node
    ll_Node *newNode = malloc(sizeof(ll_Node));
    
    newNode->next_node = NULL;
    newNode->prev_node = list->tail_node;    
    
    // store the data
    newNode->data = malloc(size);
    memcpy(newNode->data, data, size); 
    
    newNode->size = size;
    
    // if its the first node, update head node
    if (list->node_count == 0){
        list->head_node = newNode;
    }
    else
    // if not, link the current tail node to itoa
    {
        ll_Node *prev_node = list->tail_node;
        prev_node->next_node = newNode;
    }
    
    // now update the tail node
    list->tail_node = newNode;
    
    // update node count and size of whole list
    list->node_count++;
    list->size = list->size + size;    
}

void ll_insertBefore(list, node, data, size)
linkedList *list;
ll_Node *node;
void *data;
size_t size;{
    // create the node
    ll_Node *newNode = malloc(sizeof(ll_Node));

    // link next to the existing    
    newNode->next_node = node;    
    // link prev to the existing's prev
    newNode->prev_node = node->prev_node;

    // link existing one's prev to new one if there is one
    ll_Node *prevNode = ll_getPrev(node);
    if (prevNode != NULL){
        prevNode->next_node = newNode;
    }
    
    // link existing one back to new one
    node->prev_node = newNode;
    
    
    // store the data
    newNode->data = malloc(size);
    memcpy(newNode->data, data, size); 
    
    newNode->size = size;
    
    // if its the first node, update head node
    if (list->head_node == node){
        list->head_node = newNode;
    }

    // note this cannot be the tail because its being inserted before an existing node.
    
    // update node count and size of whole list
    list->node_count++;
    list->size = list->size + size;        
}

void ll_insertAfter(list, node, data, size)
linkedList *list;
ll_Node *node;
void *data;
size_t size;{
    // create the node
    ll_Node *newNode = malloc(sizeof(ll_Node));

    // link prev to the existing
    newNode->prev_node = node;
    // link next to the existing's next
    newNode->next_node = node->next_node;    


    // link existing one's next to new one if there is one
    ll_Node *nextNode = ll_getNext(node);
    if (nextNode != NULL){
        nextNode->prev_node = newNode;
    }
    
    // link existing one to new one
    node->next_node = newNode;
    
    
    // store the data
    newNode->data = malloc(size);
    memcpy(newNode->data, data, size); 
    
    newNode->size = size;
    
    // if its the last node, update tail node
    if (list->tail_node == node){
        list->tail_node = newNode;
    }

    // note this cannot be the head because its being inserted after an existing node.
    
    // update node count and size of whole list
    list->node_count++;
    list->size = list->size + size;        
}

void ll_removeNode(list, node)
linkedList *list;
ll_Node *node;{
    // link the previous and next nodes
    ll_Node *prev_N = ll_getPrev(node);
    ll_Node *next_N = ll_getNext(node);
    
    if (prev_N == NULL){
        // This is the head node so must update that
        list->head_node = next_N;
    }
    else{
        prev_N->next_node = node->next_node;
    }
    
    if (next_N == NULL){
        // This is the tail node so must update that
        list->tail_node = prev_N;
    }
    else{
        next_N->prev_node = node->prev_node;
    }
    
    // update list
    list->node_count--;
    list->size = list->size - node->size;
    
    // free memory of this node
    free(node->data);
    free(node);
}

void ll_removeBefore(list, node)
linkedList *list;
ll_Node *node;{
    ll_Node *target_node = ll_getPrev(node);
    
    ll_removeNode(list, target_node);
}

void ll_removeAfter(list, node)
linkedList *list;
ll_Node *node;{
    ll_Node *target_node = ll_getNext(node);
    
    ll_removeNode(list, target_node);    
}

void ll_destroyList(list)
linkedList *list;{
    // traverse entire list removing each node
    ll_Node *node = ll_getHead(list);
    
    while (node != NULL){
        ll_removeNode(list, node);
        node = ll_getHead(list);
    }
}

void* ll_getData(node)
ll_Node *node;{
    return node->data;
}

void ll_changeData(node, data, size)
ll_Node *node;
void *data;
size_t size;{
    // first unallocate the existing data, there will always be something as nodes are always created with data
    free(node->data);
    
    // now store the new data
    node->data = malloc(size);
    memcpy(node->data, data, size);         
}

