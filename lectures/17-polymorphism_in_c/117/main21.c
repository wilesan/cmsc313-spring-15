/* File: main21.c

   Testing out list of lists functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_int.h"
#include "ll_double.h"
#include "ll_string.h"
#include "ll_list.h"

base_node *make_int_list() ;
base_node *make_double_list() ;
base_node *make_mixed_list() ;
base_node *make_string_list() ;


int main() {
   base_node *root_list, *temp_list ;

   printf("New list: \n") ;
   root_list = LL_New() ;
  
   LL_Insert(root_list, new_int_node(17)) ;

   temp_list = make_int_list() ;
   LL_Insert(root_list, new_ll_node(temp_list)) ;

   LL_Insert(root_list, new_double_node(23.0)) ;

   temp_list = make_double_list() ;
   LL_Insert(root_list, new_ll_node(temp_list)) ;

   temp_list = make_mixed_list() ;
   LL_Insert(root_list, new_ll_node(temp_list)) ;

   LL_Insert(root_list, new_str_node("Frodo")) ;

   temp_list = make_string_list() ;
   LL_Insert(root_list, new_ll_node(temp_list)) ;

   LL_Print(root_list) ;

   LL_Destroy(root_list) ;

   return 0 ;
}


base_node *make_int_list() {
   base_node *list1 ;
   int_node *ptr ;

   list1 = LL_New() ;
   LL_Insert(list1, new_int_node(72)) ;
   LL_Insert(list1, new_int_node(94)) ;
   LL_Insert(list1, new_int_node(31)) ;
   LL_Insert(list1, new_int_node(44)) ;
   LL_Insert(list1, new_int_node(57)) ;
   LL_Insert(list1, new_int_node(18)) ;
   LL_Insert(list1, new_int_node(2)) ;

   LL_Delete(list1) ;

   ptr = (int_node *) LL_First(list1) ;
   
   base_node *temp_list = LL_New() ;
   while( ( ptr = (int_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;

   return list1 ;
}



base_node *make_double_list() {
   base_node *list1 ;
   double_node *ptr ;

   list1 = LL_New() ;
   LL_Insert(list1, new_double_node(72.1)) ;
   LL_Insert(list1, new_double_node(94.2)) ;
   LL_Insert(list1, new_double_node(31.3)) ;
   LL_Insert(list1, new_double_node(44.4)) ;
   LL_Insert(list1, new_double_node(57.5)) ;
   LL_Insert(list1, new_double_node(18.6)) ;
   LL_Insert(list1, new_double_node(2.7)) ;

   LL_Delete(list1) ;

   ptr = (double_node *) LL_First(list1) ;
   
   base_node *temp_list = LL_New() ;
   while( ( ptr = (double_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;

   return list1 ;
}


base_node *make_mixed_list() {
   base_node *list1 ;
   base_node *ptr ;

   list1 = LL_New() ;
   LL_Insert(list1, new_int_node(72)) ;
   LL_Insert(list1, new_double_node(94.1)) ;
   LL_Insert(list1, new_int_node(31)) ;
   LL_Insert(list1, new_int_node(44)) ;
   LL_Insert(list1, new_double_node(57.2)) ;
   LL_Insert(list1, new_double_node(18.7)) ;
   LL_Insert(list1, new_int_node(2)) ;

   LL_Delete(list1) ;

   ptr = (base_node *) LL_First(list1) ;
   
   base_node *temp_list = LL_New() ;
   while( ( ptr = (base_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;

   return list1 ;
}


base_node *make_string_list() {
   base_node *list1 ;
   str_node *ptr ;

   list1 = LL_New() ;
   LL_Insert(list1, new_str_node("Hello")) ;
   LL_Insert(list1, new_str_node("World. ")) ;
   LL_Insert(list1, new_str_node("My name is")) ;
   LL_Insert(list1, new_str_node("Zaphod Beeblebrox. ")) ;
   LL_Insert(list1, new_str_node("I stole the")) ;
   LL_Insert(list1, new_str_node("Heart of Gold. ")) ;
   LL_Insert(list1, new_str_node("Good-bye!")) ;

   LL_Delete(list1) ;

   ptr = (str_node *) LL_First(list1) ;
   
   base_node *temp_list = LL_New() ;
   while( ( ptr = (str_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;

   return list1 ;
}
