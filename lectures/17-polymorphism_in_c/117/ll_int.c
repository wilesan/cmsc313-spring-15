/* File: ll_int.c

   Implements functions supporting linked lists of int.

*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_int.h"


one_ftype Int_VFuncs[2]  = { 
   (one_ftype) &print_int_node, 
   (one_ftype) &del_int_node 
} ;


void print_int_node(int_node *ptr) {
   printf("%d  ", ptr->data) ;   
   return ;
}

void del_int_node(int_node *ptr) {
   free(ptr) ;
   return ;
}

int_node *new_int_node (int data) {
   int_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_int_node()!\n") ;
      exit(1) ;
   }
   ptr->vfunc = Int_VFuncs ;
   ptr->data = data ;
   ptr->next = NULL ;
   return ptr ;
}
