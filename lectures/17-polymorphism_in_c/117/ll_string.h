#ifndef _LL_STRING_H
#define  _LL_STRING_H

#include "ll.h"

typedef struct str_node {
   one_ftype *vfunc ;
   struct str_node *next ;
   char *data ;
} str_node ;


str_node *new_str_node (const char *str) ;

void del_str_node(str_node *ptr) ;

void print_str_node(str_node *ptr) ;

extern one_ftype Str_VFuncs[] ;

#endif
