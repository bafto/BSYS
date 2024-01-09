# Concurrent Counter

usage: `concurrent_counter <num_threads> <counter>`
Each thread counts counter times

number of cpus = 8

## Results

`concurrent_counter 1 10000`
Average: 661 usec
`concurrent_counter 2 10000`
Average: 4308 usec
`concurrent_counter 4 10000`
Average: 8035 usec
`concurrent_counter 8 10000`
Average: 16708 usec
`concurrent_counter 16 10000`
Average: 24505 usec
`concurrent_counter 32 10000`
Average: 40052 usec

