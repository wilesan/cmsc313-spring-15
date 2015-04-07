#ifndef _LL_LIST_H
#define  _LL_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

typedef struct ll_node {
   one_ftype *vfunc ;
   struct ll_node *next ;
   base_node *data ;
} ll_node ;


ll_node *new_ll_node (base_node *lptr) ;

void del_ll_node(ll_node *ptr) ;

void print_ll_node(ll_node *ptr) ;

extern one_ftype List_VFuncs[] ;

#endif
