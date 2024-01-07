# Concurrent Counter

usage: `concurrent_counter <num_threads> <counter>`
Each thread counts counter times

## Results

`concurrent_counter 1 10000`
Average: 661 usec
`concurrent_counter 2 10000`
Average: 4308 usec
`concurrent_counter 3 10000`
Average: 5391 usec
`concurrent_counter 4 10000`
Average: 8035 usec
`concurrent_counter 8 10000`
Average: 1596 usec
