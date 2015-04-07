/* File: main14.c

   Using generic functions in ll.c to implement
   a linked list of integers and linked list of doubles.

   This version has a virtual function table.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"


typedef struct int_node {
   one_ftype *vfunc ;
   struct int_node *next ;
   int data ;
} int_node ;


void print_int_node(int_node *ptr) {
   printf("%d  ", ptr->data) ;   
   return ;
}


void del_int_node(int_node *ptr) {
   free(ptr) ;
   return ;
}


one_ftype Int_VFuncs[2] = { 
   (one_ftype) &print_int_node, 
   (one_ftype) &del_int_node 
} ;


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


typedef struct double_node {
   one_ftype *vfunc ;
   struct double_node *next ;
   double data ;
} double_node ;


void print_double_node(double_node *ptr) {
   printf("%f  ", ptr->data) ;   
   return ;
}


void del_double_node(double_node *ptr) {
   free(ptr) ;
   return ;
}


one_ftype Double_VFuncs[2] = { 
   (one_ftype) &print_double_node, 
   (one_ftype) &del_double_node 
} ;


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



int main() {
   base_node *list1 ;
   base_node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, new_int_node(72)) ;
   LL_Insert(list1, new_double_node(94.1)) ;
   LL_Insert(list1, new_int_node(31)) ;
   LL_Insert(list1, new_int_node(44)) ;
   LL_Insert(list1, new_double_node(57.2)) ;
   LL_Insert(list1, new_double_node(18.7)) ;
   LL_Insert(list1, new_int_node(2)) ;

   LL_Print(list1) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1) ;


   printf("First item: ") ;
   ptr = (base_node *) LL_First(list1) ;
   (* (ptr->vfunc[PRINT_VF])) (ptr) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (base_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1) ;

   LL_Destroy(list1) ;
   return 0 ;
}
