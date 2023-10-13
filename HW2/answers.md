# Homework 2

# Question 1

The parent and child process seem to be independent.
One can change x and the other is not affected.
The do not share the same address space.

# Question 2

Both parent and child can access the file, that means that file descriptors get inherited (just like we can see with STD_OUT/ERR/IN)

When writing concurrently, for me the parent always finishes first and there are no problems.
Maybe input buffering? I would expect the writes to get mixed up.

# Question 3

I used pipes to singal child-completion by closing a pipe which was setup by the parent.
When the pipe closes, the parent knows that the child is done.
Of course you could send actual messages, but for now I just emulated wait.

# Question 4

No idea why there are so many variants.
You could just have 1 variant where you can specify arguments and environment seperately.
The only reason I see is different search behaviour with environment variables (like PATH)

# Question 5

Wait in the child returns an error because it has no children itself to wait for.

# Question 6

Did this already

# Question 7

Closing the STDOUT_FILENO leads to printf failing in the child, but does not affect the parent.

# Question 8

q8.c