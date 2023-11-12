# HW7

## Question 1

`./null`:

Segmentation fault (core dumped)

## Question 2

`gdb ./null`:

Program received signal SIGSEGV, Segmentation fault.
0x000055555555513d in main () at null.c:5
5	    return *p;

## Question 3

`valgrind --leak-check=yes ./null`:

==6133== Memcheck, a memory error detector
==6133== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6133== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6133== Command: ./null
==6133== 
==6133== Invalid read of size 4
==6133==    at 0x10913D: main (null.c:5)
==6133==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==6133== 
==6133== 
==6133== Process terminating with default action of signal 11 (SIGSEGV)
==6133==  Access not within mapped region at address 0x0
==6133==    at 0x10913D: main (null.c:5)
==6133==  If you believe this happened as a result of a stack
==6133==  overflow in your program's main thread (unlikely but
==6133==  possible), you can try to increase the size of the
==6133==  main thread stack using the --main-stacksize= flag.
==6133==  The main thread stack size used in this run was 8388608.
==6133== 
==6133== HEAP SUMMARY:
==6133==     in use at exit: 0 bytes in 0 blocks
==6133==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6133== 
==6133== All heap blocks were freed -- no leaks are possible
==6133== 
==6133== For lists of detected and suppressed errors, rerun with: -s
==6133== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)

## Question 4

`./stupid`:

`gdb ./stupid`:

Starting program: /home/bafto/Desktop/HTWG/WiSe23/BSYS/HW7/stupid 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[Inferior 1 (process 6357) exited normally]

`valgrind --leak-check=yes ./stupid`:

==6368== Memcheck, a memory error detector
==6368== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6368== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6368== Command: ./stupid
==6368== 
==6368== 
==6368== HEAP SUMMARY:
==6368==     in use at exit: 100 bytes in 1 blocks
==6368==   total heap usage: 1 allocs, 0 frees, 100 bytes allocated
==6368== 
==6368== 100 bytes in 1 blocks are definitely lost in loss record 1 of 1
==6368==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6368==    by 0x10915E: main (stupid.c:4)
==6368== 
==6368== LEAK SUMMARY:
==6368==    definitely lost: 100 bytes in 1 blocks
==6368==    indirectly lost: 0 bytes in 0 blocks
==6368==      possibly lost: 0 bytes in 0 blocks
==6368==    still reachable: 0 bytes in 0 blocks
==6368==         suppressed: 0 bytes in 0 blocks
==6368== 
==6368== For lists of detected and suppressed errors, rerun with: -s
==6368== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

## Question 5

`./null_2_0`:

`gdb ./null_2_0`:

Starting program: /home/bafto/Desktop/HTWG/WiSe23/BSYS/HW7/null_2_0 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[Inferior 1 (process 6521) exited normally]

`valgrind --leak-check=yes ./null_2_0`:

==6550== Memcheck, a memory error detector
==6550== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6550== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6550== Command: ./null_2_0
==6550== 
==6550== Invalid write of size 4
==6550==    at 0x10918D: main (null_2_0.c:5)
==6550==  Address 0x4aa01d0 is 224 bytes inside an unallocated block of size 4,194,032 in arena "client"
==6550== 
==6550== 
==6550== HEAP SUMMARY:
==6550==     in use at exit: 0 bytes in 0 blocks
==6550==   total heap usage: 1 allocs, 1 frees, 100 bytes allocated
==6550== 
==6550== All heap blocks were freed -- no leaks are possible
==6550== 
==6550== For lists of detected and suppressed errors, rerun with: -s
==6550== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


## Question 6

`./null_3_0`:

27

`valgrind --leak-check=yes ./null_2_0`:

==6699== Memcheck, a memory error detector
==6699== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6699== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6699== Command: ./null_3_0
==6699== 
==6699== Invalid read of size 4
==6699==    at 0x1091C5: main (null_3_0.c:8)
==6699==  Address 0x4aa0068 is 40 bytes inside a block of size 100 free'd
==6699==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6699==    by 0x1091BC: main (null_3_0.c:7)
==6699==  Block was alloc'd at
==6699==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6699==    by 0x10919E: main (null_3_0.c:5)
==6699== 
27
==6699== 
==6699== HEAP SUMMARY:
==6699==     in use at exit: 0 bytes in 0 blocks
==6699==   total heap usage: 2 allocs, 2 frees, 1,124 bytes allocated
==6699== 
==6699== All heap blocks were freed -- no leaks are possible
==6699== 
==6699== For lists of detected and suppressed errors, rerun with: -s
==6699== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

## Question 7

`./even_stupider`:

free(): invalid pointer
Aborted (core dumped)

`valgrind --leak-check=yes ./even_stupider`:

==20340== Memcheck, a memory error detector
==20340== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20340== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==20340== Command: ./even_stupider
==20340== 
==20340== Invalid free() / delete / delete[] / realloc()
==20340==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20340==    by 0x1091C0: main (even_stupider.c:7)
==20340==  Address 0x4aa0068 is 40 bytes inside a block of size 100 alloc'd
==20340==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20340==    by 0x10919E: main (even_stupider.c:5)
==20340== 
27
==20340== 
==20340== HEAP SUMMARY:
==20340==     in use at exit: 100 bytes in 1 blocks
==20340==   total heap usage: 2 allocs, 2 frees, 1,124 bytes allocated
==20340== 
==20340== 100 bytes in 1 blocks are definitely lost in loss record 1 of 1
==20340==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20340==    by 0x10919E: main (even_stupider.c:5)
==20340== 
==20340== LEAK SUMMARY:
==20340==    definitely lost: 100 bytes in 1 blocks
==20340==    indirectly lost: 0 bytes in 0 blocks
==20340==      possibly lost: 0 bytes in 0 blocks
==20340==    still reachable: 0 bytes in 0 blocks
==20340==         suppressed: 0 bytes in 0 blocks
==20340== 
==20340== For lists of detected and suppressed errors, rerun with: -s
==20340== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

## Question 8

...

Kleine Größe: vektor gut
Große Größe: LL gut

## Question 9

-
