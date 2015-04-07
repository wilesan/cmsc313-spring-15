/* File: main17.c

   Test out linked list of int
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_int.h"

int main() {
   base_node *list1 ;
   int_node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, new_int_node(72)) ;
   LL_Insert(list1, new_int_node(94)) ;
   LL_Insert(list1, new_int_node(31)) ;
   LL_Insert(list1, new_int_node(44)) ;
   LL_Insert(list1, new_int_node(57)) ;
   LL_Insert(list1, new_int_node(18)) ;
   LL_Insert(list1, new_int_node(2)) ;

   LL_Print(list1) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1) ;


   printf("First item: ") ;
   ptr = (int_node *) LL_First(list1) ;
   printf("%d  ", ptr->data) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (int_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1) ;

   LL_Destroy(list1) ;
   return 0 ;
}
