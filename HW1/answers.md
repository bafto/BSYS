# Homework 1

## Note

'job' and 'process' are used interchangeably

The simulation often/sometimes takes an additional cycle when all the processes are done.
In this cycle no IO or CPU usage happens, but it is still counted

## Question 1

`$python2 process-run.py -l 5:100,5:100`

CPU should be 100% used, because the chance for io is 0% for every process.

## Question 2

`$python2 process-run.py -l 4:100,1:0`

The whole thing should take 9 cycles, 4 for cpu, and 5 for IO.

It actually took 5 for cpu and 4 for IO, because the cycle where the IO request is issued is counted as cpu, but is still calculated into the 'IO-length'.

## Question 3

`$python2 process-run.py -l 1:0,4:100`

Now the whole thing should only take 5 cycles, because while the IO runs, the cpu can be used by the other process.

## Question 4

`$python2 process-run.py -l 1:0,4:100 -S SWITCH_ON_END`

Now it should take 9 cycles again, because the OS waits for the first process to finish until it runs the next job

## Question 5

`$python2 process-run.py -l 1:0,4:100 -S SWITCH_ON_IO`

Now it should be just like in Question 3

## Question 6

`$python2 process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER`

When the first process starts it's IO the second process should start and run to the end.
Once it is over, the OS does NOT switch back to the IO process, but rather runs the other jobs first.
This is inefficient, because while the other processes run, the IO process could do IO.
In this simulation, the cpu is not always busy.

## Question 7

`$python2 process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE`

This should run more efficiently, because once one IO request is done, the next one can start, and during every IO request, other processes can use the CPU.

Generally it seems good to switch back to the IO process after an IO request has finished, because it seems reasonable to assume that a process that did IO once will do it again soon.

## Question 8

`python2 process-run.py -s 1 -l 3:50,3:50 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE`

The SWITCH_ON_IO option should always be used, as SWITCH_ON_END does not utilize the cpu as much.

Using IO_RUN_IMMEDIATE vs IO_RUN_LATER seems to make less of a difference when all processes might issue IO.
The cpu and IO utilization always seems the same, no matter what IO flag is set.