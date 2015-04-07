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
node *LL_New() {
   node *ptr ;   

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "malloc() failed in LL_New().\n") ;
      exit(1) ;
   }

   ptr->next = NULL ;
   return ptr ;
}



// Inserts new node with data at beginning of linked list.
//
void LL_Insert(node *header, DATA_TYPE data) {
   node *ptr ;
    
   assert(header) ;
   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "malloc() failed in LL_Insert().\n") ;
      exit(1) ;
   }
     
   ptr->data = data ; 
   ptr->next = header->next ;
   header->next = ptr ;
   return ;
}


// returns pointer to first item in the list.
// NULL returned if list is empty.
//
node *LL_First(node *header) {

   assert(header) ;
   return header->next ;
}


// remove and return first node in linked list
// NULL is returned if list is empty

node *LL_Extract(node *header) {
   node *ptr ;

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
void LL_Delete(node *header) {
   node *ptr ;
   
   assert(header) ;
   ptr = LL_Extract(header) ;
   free(ptr) ;

   return ;
}


// Make list into empty list
//
void LL_Empty(node *header) {
   node *ptr, *temp_ptr ;

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

void LL_Destroy(node *header) {
   LL_Empty(header);
   free(header) ;
   return ;
}


// Print all nodes in linked list
//
void LL_Print(node *header) {
   node *ptr ;

   assert(header) ;
   ptr = header->next ;
   while(ptr != NULL) {
      printf(DATA_TYPE_FORMAT, ptr->data) ;
      ptr = ptr->next ;
   }
   printf("\n") ;
}


