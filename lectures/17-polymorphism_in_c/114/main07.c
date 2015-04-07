/* File: main07.c

   Uses ll.h and ll.c for generic linked list routines.
   Must define new_str_node() and print_str_node() here.
   Can only use constant strings!
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

typedef struct str_node {
   struct str_node *next ;
   const char *data ;
} str_node ;


str_node *new_str_node (const char *str) {
   str_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->data = str ;
   ptr->next = NULL ;
   return ptr ;
}


void print_str_node(str_node *ptr) {
   printf("%s ", ptr->data) ;   
   return ;
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

   LL_Print(list1, (print_ftype) &print_str_node) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1, (print_ftype) &print_str_node) ;


   printf("First item: ") ;
   ptr = (str_node *) LL_First(list1) ;
   printf("%s ", ptr->data) ;
   printf("\n") ;
   // ptr->data[1] = 'a' ;  // would cause compilation error
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (str_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1, (print_ftype) &print_str_node) ;

   LL_Destroy(list1) ;
   return 0 ;
}
