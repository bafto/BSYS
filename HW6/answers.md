# HW6 

## Question 1

-

## Question 2

`free`:

               total        used        free      shared  buff/cache   available
Mem:        16148028     1321072    12554080      387788     2272876    14116360
Swap:        2097148           0     2097148

Scheint korrekt

## Question 3

eat.c

# Question 4

`./eat 100 -1 &`
`free --human`:


               total        used        free      shared  buff/cache   available
Mem:            15Gi       1,5Gi        11Gi       322Mi       2,3Gi        13Gi
Swap:          2,0Gi          0B       2,0Gi


`./eat 1024 -1 &`
`free --human`:

               total        used        free      shared  buff/cache   available
Mem:            15Gi       1,9Gi        11Gi       318Mi       2,3Gi        12Gi
Swap:          2,0Gi          0B       2,0Gi

               total        used        free      shared  buff/cache   available
Mem:            15Gi       2,4Gi        10Gi       376Mi       2,4Gi        12Gi
Swap:          2,0Gi          0B       2,0Gi

Es braucht ein bisschen bis der Speicher wirklich genutzt wird
Bei sehr viel Speicher (2048MB) reicht ein einziger aufruf von malloc nicht mehr.

## Question 5

-

## Question 6

`./eat 100 -1 &`
`pmap $! -x`:

4741:   ./eat 100 -1
Address           Kbytes     RSS   Dirty Mode  Mapping
0000555a900c8000       4       4       0 r---- eat
0000555a900c9000       4       4       0 r-x-- eat
0000555a900ca000       4       4       0 r---- eat
0000555a900cb000       4       4       4 r---- eat
0000555a900cc000       4       4       4 rw--- eat
0000555a9134f000     132       4       4 rw---   [ anon ]
00007f47b149d000  101772  101772  101772 rw---   [ anon ]
00007f47b7800000     160     160       0 r---- libc.so.6
00007f47b7828000    1620     964       0 r-x-- libc.so.6
00007f47b79bd000     352     108       0 r---- libc.so.6
00007f47b7a15000      16      16      16 r---- libc.so.6
00007f47b7a19000       8       8       8 rw--- libc.so.6
00007f47b7a1b000      52      20      20 rw---   [ anon ]
00007f47b7af5000    1040    1036    1036 rw---   [ anon ]
00007f47b7c13000       8       4       4 rw---   [ anon ]
00007f47b7c15000       8       8       0 r---- ld-linux-x86-64.so.2
00007f47b7c17000     168     168       0 r-x-- ld-linux-x86-64.so.2
00007f47b7c41000      44      40       0 r---- ld-linux-x86-64.so.2
00007f47b7c4d000       8       8       8 r---- ld-linux-x86-64.so.2
00007f47b7c4f000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffee7738000     136      92      92 rw---   [ stack ]
00007ffee77dc000      16       0       0 r----   [ anon ]
00007ffee77e0000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB          105580  104440  102976

Bei einem Browser ist der output zu groß, da er so viele libraries und kleine allocations benutzt

## Question 7

""

## Question 8

`./eat 100 -1 &`
`pmap $! -x`:

5065:   ./eat 100 -1
Address           Kbytes     RSS   Dirty Mode  Mapping
0000559e80b26000       4       4       0 r---- eat
0000559e80b27000       4       4       0 r-x-- eat
0000559e80b28000       4       4       0 r---- eat
0000559e80b29000       4       4       4 r---- eat
0000559e80b2a000       4       4       4 rw--- eat
0000559e816f7000     132       4       4 rw---   [ anon ]
00007f796959c000  102800  102800  102800 rw---   [ anon ]
00007f796fa00000     160     160       0 r---- libc.so.6
00007f796fa28000    1620     964       0 r-x-- libc.so.6
00007f796fbbd000     352     108       0 r---- libc.so.6
00007f796fc15000      16      16      16 r---- libc.so.6
00007f796fc19000       8       8       8 rw--- libc.so.6
00007f796fc1b000      52      20      20 rw---   [ anon ]
00007f796fc42000      12       8       8 rw---   [ anon ]
00007f796fc5f000       8       4       4 rw---   [ anon ]
00007f796fc61000       8       8       0 r---- ld-linux-x86-64.so.2
00007f796fc63000     168     168       0 r-x-- ld-linux-x86-64.so.2
00007f796fc8d000      44      40       0 r---- ld-linux-x86-64.so.2
00007f796fc99000       8       8       8 r---- ld-linux-x86-64.so.2
00007f796fc9b000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffcbfdc0000     136      92      92 rw---   [ stack ]
00007ffcbfdf6000      16       0       0 r----   [ anon ]
00007ffcbfdfa000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB          105580  104440  102976

`./eat 1024 -1 &`
`pmap $! -x`:

5107:   ./eat 1024 -1
Address           Kbytes     RSS   Dirty Mode  Mapping
0000560b0e558000       4       4       0 r---- eat
0000560b0e559000       4       4       0 r-x-- eat
0000560b0e55a000       4       4       0 r---- eat
0000560b0e55b000       4       4       4 r---- eat
0000560b0e55c000       4       4       4 rw--- eat
0000560b0fccb000     132       4       4 rw---   [ anon ]
00007fe48f701000 1051644 1051644 1051644 rw---   [ anon ]
00007fe4cfa00000     160     160       0 r---- libc.so.6
00007fe4cfa28000    1620     964       0 r-x-- libc.so.6
00007fe4cfbbd000     352     108       0 r---- libc.so.6
00007fe4cfc15000      16      16      16 r---- libc.so.6
00007fe4cfc19000       8       8       8 rw--- libc.so.6
00007fe4cfc1b000      52      20      20 rw---   [ anon ]
00007fe4cfc49000    1040    1036    1036 rw---   [ anon ]
00007fe4cfd67000       8       4       4 rw---   [ anon ]
00007fe4cfd69000       8       8       0 r---- ld-linux-x86-64.so.2
00007fe4cfd6b000     168     168       0 r-x-- ld-linux-x86-64.so.2
00007fe4cfd95000      44      40       0 r---- ld-linux-x86-64.so.2
00007fe4cfda1000       8       8       8 r---- ld-linux-x86-64.so.2
00007fe4cfda3000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffe8b5a1000     136      92      92 rw---   [ stack ]
00007ffe8b5cc000      16       0       0 r----   [ anon ]
00007ffe8b5d0000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB         1055452 1054312 1052848
