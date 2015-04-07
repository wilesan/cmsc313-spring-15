/* File: ll_string.c

   Implements linked list of strings function

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_string.h"

#define NDEBUG

one_ftype Str_VFuncs[2] = { 
   (one_ftype) &print_str_node, 
   (one_ftype) &del_str_node 
} ;


void print_str_node(str_node *ptr) {
   printf("%s ", ptr->data) ;   
   return ;
}


void del_str_node(str_node *ptr) {
#ifndef NDEBUG
   fprintf (stderr, "Deleting memory for string: %s\n", ptr->data) ;
#endif
   free(ptr->data) ;
   free(ptr) ;
   return ;
}


str_node *new_str_node (const char *str) {
   str_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->vfunc = Str_VFuncs ;
   ptr->data = strdup(str) ;
   if (ptr->data == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->next = NULL ;
   return ptr ;
}
