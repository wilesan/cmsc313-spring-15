Directory: ll4

Achieves genericity using void * pointers.

Note that ll.c does not have to be recompiled to work with a new data
type.

LL_Insert now takes a NODE for its second argument. This has to be
malloc-ed by the caller.

LL_Print needs a print function for its second argument.

Cannot have mix of int and double in the same linked list.


void_ptr.c: check out how much the compiler would complain about
assigning int pointers to void pointers and vice versa.

main04.c: linked list of int

main05.c: linked list of double

main06.c: linked list of int and of double

main07.c: linked list of constant string.
   Note: doesn't deallocate properly so can't have
   linked list of strdup-ed stirngs.

