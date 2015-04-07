/* File: main11.c

   Using generic linked list functions in ll.c
   to implement a linked list of const strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

typedef struct str_node {
   print_ftype print_func ;
   struct str_node *next ;
   const char *data ;
} str_node ;


void print_str_node(str_node *ptr) {
   printf("%s ", ptr->data) ;   
   return ;
}

str_node *new_str_node (const char *str) {
   str_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->print_func = (print_ftype) &print_str_node ;
   ptr->data = str ;
   ptr->next = NULL ;
   return ptr ;
}




int main() {
   base_node *list1 ;
   str_node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, new_str_node("Hello")) ;
   LL_Insert(list1, new_str_node("World. ")) ;
   LL_Insert(list1, new_str_node("My name is")) ;
   LL_Insert(list1, new_str_node("Zaphod Beeblebrox. ")) ;
   LL_Insert(list1, new_str_node("I stole the")) ;
   LL_Insert(list1, new_str_node("Heart of Gold. ")) ;
   LL_Insert(list1, new_str_node("Good-bye!")) ;

   LL_Print(list1) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1) ;


   printf("First item: ") ;
   ptr = (str_node *) LL_First(list1) ;
   printf("%s ", ptr->data) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (str_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1) ;

   LL_Destroy(list1) ;
   return 0 ;
}
