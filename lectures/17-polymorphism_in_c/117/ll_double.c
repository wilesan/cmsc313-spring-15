/* File: ll_double.c

   Implements functions for linked lists of double
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_double.h"


one_ftype Double_VFuncs[2] = { 
   (one_ftype) &print_double_node, 
   (one_ftype) &del_double_node 
} ;


void del_double_node(double_node *ptr) {
   free(ptr) ;
   return ;
}


void print_double_node(double_node *ptr) {

   printf("%f  ", ptr->data) ;   
   return ;
}


double_node *new_double_node (double data) {
   double_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_double_node()!\n") ;
      exit(1) ;
   }
   ptr->vfunc = Double_VFuncs ;
   ptr->data = data ;
   ptr->next = NULL ;
   return ptr ;
}
