/* File: ll_list.c

   Implements functions for linked list nodes
   that point to another linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_list.h"


one_ftype List_VFuncs[2] = { 
   (one_ftype) &print_ll_node, 
   (one_ftype) &del_ll_node 
} ;


void print_ll_node(ll_node *ptr) {
   printf("\n\n<LIST>\n") ;
   LL_Print(ptr->data) ;
   printf("</LIST>\n\n") ;
   return ;
}


void del_ll_node(ll_node *ptr) {
   LL_Destroy(ptr->data) ;
   return ;
}


ll_node *new_ll_node (base_node *lptr) {
   ll_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_ll_node()!\n") ;
      exit(1) ;
   }
   ptr->vfunc = List_VFuncs ;
   ptr->data = lptr ;
   ptr->next = NULL ;
   return ptr ;
}
