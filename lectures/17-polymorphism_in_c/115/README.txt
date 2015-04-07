Directory: ll5

This version allows mixed data types in a single linked list.

Each base_node now includes a function pointer to a function
that prints out the data in the node.

Note that the print function takes an entire node for its argument, not
just the data field, since the generic linked list functions do not know
about the data fields at all.

ll.c: Note how the LL_Print function invokes the function stored in each
node to print.  Also, LL_Print no longer needs a second parameter.

main08.c: note how pointer to the print function is stored.

main09.c: does same with doubles.

main10.c: Polymorphism!! Single linked list has both ints and doubles.

main11.c: linked list of constant strings.
   Still don't like that we can't have non-const strings.
