# cmsc313-spring-15
Repository for Spring '15 offering of CMSC 313 at UMBC

All code and supporting files used during lectures is in the lectures/ folder.

All code and supporting files for projects is in the projects/ folder.

# Building Your Code

Since linux GL is 64 bits and we’ll be dealing only with 32 bit assembly in this class, you’ll need to build your code in a special way:

```
	$ nasm -f elf -g -F stabs yourprogram.asm
	$ ld -o yourprogram yourprogram.o -melf_i386
	$ ./yourprogram
```

The C programming parts of the class will also link in code from nasm, and since all of our assembly code is 32-bit, we need to tell the compiler to build 32-bit code as well:

```
	$ gcc hello.c
	$ file a.out 
a.out: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.18, not stripped
```

The “64-bit” highlighted above shows that our program was built as a 64-bit executable.  Now, we’ll build for 32-bit:

```
	$ gcc -m32 hello.c
	$ file a.out
a.out: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.18, not stripped
```

Now, a.out is a 32-bit executable.

