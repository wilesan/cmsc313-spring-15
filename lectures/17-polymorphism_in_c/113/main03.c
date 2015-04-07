/* File: main03.c

   test out linked list ADT

   ll.h #defines DATA_TYPE and DATA_TYPE_FORMAT as double and "%f  "

*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main() {
   node *list1 ;
   node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, 72.1) ;
   LL_Insert(list1, 94.2) ;
   LL_Insert(list1, 31.3) ;
   LL_Insert(list1, 44.4) ;
   LL_Insert(list1, 57.5) ;
   LL_Insert(list1, 18.6) ;
   LL_Insert(list1, 2.7) ;
   LL_Print(list1) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1) ;


   printf("First item: ") ;
   ptr = LL_First(list1) ;
   printf(DATA_TYPE_FORMAT, ptr->data) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   node *temp_list = LL_New() ;
   while( ( ptr = LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr->data) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1) ;

   LL_Destroy(list1) ;
   return 0 ;
}
