/* File: main19.c

   Testing out linked list ADT.
   Using int_node and double_node simultaneously
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_int.h"
#include "ll_double.h"


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
