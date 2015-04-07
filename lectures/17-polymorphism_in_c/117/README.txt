Directory: ll7

This version splits up the main files and place header and
implementation of various versions of the linked lists in separate
files. (E.g., ll_int.h and ll_int.c.)  The linked list implementations
can be compiled separately and the *.o files can be placed in a library
using the ar command.

To create a library file:

   ar -cr libll.a ll.o ll_int.o ll_double.o ll_string.o ll_list.o

To compile using the library:

   gcc -Wall main17.c -L . -lll

To see the contents of a library:

  ar -t libll.a


Files:

ll.c, ll.h: 
   generic linked list functions

ll_double.c, ll_double.h:
   linked list of doubles

ll_int.c, ll_int.h:
   linked list of int

ll_string.c, ll_string.h:
   linked list of string
   Compile with -DNDEBUG to remove debugging printf statements

ll_list.c, ll_list.h:
   linked list of linked list
   Check out the implementation of del_ll_node() and print_ll_node().
   They call the generic linked list Destroy and Print functions.

main17.c:
   Now all we need to do is #include "ll_int.h" to use
   the linked list of int functions.

main18.c
   Tests linked list of double.

main19.c
   Tests linked list of int and double in same list.

main20.c
   Tests linked list of strings.

main21.c
   Tests linked list of multiple types, including linked lists.

