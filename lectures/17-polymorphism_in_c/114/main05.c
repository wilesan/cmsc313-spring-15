/* File: main05.c

   Uses ll.h and ll.c for generic linked list routines.
   Must define new_double_node() and print_double_node() here.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

typedef struct double_node {
   struct double_node *next ;
   double data ;
} double_node ;


double_node *new_double_node (double data) {
   double_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_double_node()!\n") ;
      exit(1) ;
   }
   ptr->data = data ;
   ptr->next = NULL ;
   return ptr ;
}


void print_double_node(double_node *ptr) {
   printf("%f  ", ptr->data) ;   
   return ;
}


int main() {
   base_node *list1 ;
   double_node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, new_double_node(72.1)) ;
   LL_Insert(list1, new_double_node(94.2)) ;
   LL_Insert(list1, new_double_node(31.3)) ;
   LL_Insert(list1, new_double_node(44.4)) ;
   LL_Insert(list1, new_double_node(57.5)) ;
   LL_Insert(list1, new_double_node(18.6)) ;
   LL_Insert(list1, new_double_node(2.7)) ;

   LL_Print(list1, (print_ftype) &print_double_node) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1, (print_ftype) &print_double_node) ;


   printf("First item: ") ;
   ptr = (double_node *) LL_First(list1) ;
   printf("%f  ", ptr->data) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (double_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1, (print_ftype) &print_double_node) ;

   LL_Destroy(list1) ;
   return 0 ;
}
