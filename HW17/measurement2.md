# Approximate Counter

usage: `approximate_counter <num_threads> <counter> <threshhold>`
Each thread counts counter times

number of cpus was 8

## Results

`approximate_counter 1 10000 1024`
Average: 734 usec
`approximate_counter 2 10000 1024`
Average: 1232 usec
`approximate_counter 4 10000 1024`
Average: 2044 usec
`approximate_counter 8 10000 1024`
Average: 3906 usec
`approximate_counter 16 10000 1024`
Average: 7222 usec
`approximate_counter 32 10000 1024`
Average: 10900 usec

Verbesserung um Faktor ~4 im Vergleich zum concurrent_counter
