#ifndef _LL_H
#define _LL_H

#define DATA_TYPE double
#define DATA_TYPE_FORMAT "%f  "

typedef struct node {
   struct node *next ; 
   DATA_TYPE data ;
} node ;

// Returns pointer to new linked list's dummy header.
node *LL_New() ;

// Inserts new node with data at beginning of linked list.
void LL_Insert(node *header, DATA_TYPE data) ;

// returns pointer to first item in the list.
node *LL_First(node *header) ;

// remove and return first node in linked list
node *LL_Extract(node *header) ;

// Delete first node of linked list 
void LL_Delete(node *header) ;

// Make list into empty list
void LL_Empty(node *header) ;

// Destroy entire data structure.
void LL_Destroy(node *header_ptr) ;

// Print all nodes in linked list
//
void LL_Print(node *header) ;

#endif
