#ifndef _LL_H
#define _LL_H

typedef void (* print_ftype) (void *) ;

typedef struct base_node {
   print_ftype print_func ;
   struct base_node *next ; 
   // no data!!
} base_node ;



// Returns pointer to new linked list's dummy header.
base_node *LL_New() ;

// Inserts new node with data at beginning of linked list.
void LL_Insert(base_node *header, void *n) ;

// returns pointer to first item in the list.
void *LL_First(base_node *header) ;

// remove and return first node in linked list
void *LL_Extract(base_node *header) ;

// Delete first node of linked list 
void LL_Delete(base_node *header) ;

// Make list into empty list
void LL_Empty(base_node *header) ;

// Destroy entire data structure.
void LL_Destroy(base_node *header) ;

// Print all nodes in linked list
//
void LL_Print(base_node *header) ;

#endif
