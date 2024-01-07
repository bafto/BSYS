# Approximate Counter

usage: `approximate_counter <num_threads> <counter> <threshhold>`
Each thread counts counter times

number of cpus was 8

## Results

`approximate_counter 1 10000 1024`
Average: 691 usec
`approximate_counter 2 10000 1024`
Average: 3057 usec
`approximate_counter 4 10000 1024`
Average: 7236 usec
`approximate_counter 8 10000 1024`
Average: 9142 usec
`approximate_counter 16 10000 1024`
Average: 14639 usec
`approximate_counter 32 10000 1024`
Average: 24296 usec

