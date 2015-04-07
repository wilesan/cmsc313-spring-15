/* File: ll.c

   Functions supporting the linked list abstract data type.
   Assume that a dummy header is used.
*/

#include "ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Returns pointer to new linked list's dummy header.
//
base_node *LL_New() {
   base_node *ptr ;   

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "malloc() failed in LL_New().\n") ;
      exit(1) ;
   }

   ptr->next = NULL ;
   return ptr ;
}



// Inserts new node with data at beginning of linked list.
// Note: second argument is a NODE with memory allocated already.
//
void LL_Insert(base_node *header, void *n) {
   base_node *new_node = n ;
    
   assert(header) ;
   assert(new_node) ;

   new_node->next = header->next ;
   header->next = new_node ;
   return ;
}


// returns pointer to first item in the list.
// NULL returned if list is empty.
//
void *LL_First(base_node *header) {

   assert(header) ;
   return header->next ;
}


// remove and return first node in linked list
// NULL is returned if list is empty

void *LL_Extract(base_node *header) {
   base_node *ptr ;

   assert(header) ;
   ptr = header->next ;

   if (ptr) {
      header->next = ptr->next ;
      ptr->next = NULL ;  //paranoid
   }

   return (ptr) ;
}


// Delete first node of linked list 
//
void LL_Delete(base_node *header) {
   base_node *ptr ;
   
   assert(header) ;
   ptr = LL_Extract(header) ;
   free(ptr) ;

   return ;
}


// Make list into empty list
//
void LL_Empty(base_node *header) {
   base_node *ptr, *temp_ptr ;

   assert(header) ;
   ptr = header->next ;
   header->next = NULL ;

   while(ptr) {
      temp_ptr = ptr->next ; 
      ptr->next = NULL ;  // really paranoid
      free(ptr) ;
      ptr = temp_ptr ;
   }
   
   return ;
}


// Destroy entire data structure.
// No additional calls to ADT functions should be made.

void LL_Destroy(base_node *header) {
   LL_Empty(header);
   free(header) ;
   return ;
}


// Print all nodes in linked list
//
void LL_Print(base_node *header, print_ftype f) {
   base_node *ptr ;

   assert(header) ;
   ptr = header->next ;
   while(ptr != NULL) {
      (*f)(ptr) ;
      ptr = ptr->next ;
   }
   printf("\n") ;
}

