# Optimizing performance

We want to make the program run faster. To measure performance we run the following benchmark on the same computer

> ./build/compressor --benchmark

with compiler options

> CXX = gcc
> CXX_FLAGS = -O1 -g -std=c99 -Wall -Wextra -Wshadow -Wwrite-strings -Werror-implicit-function-declaration -Wundef -Wpointer-arith -Waggregate-return  -Wswitch-default -Wunreachable-code -Wformat=2 -Wmissing-prototypes -Wstrict-prototypes -Wconversion

## Benchmark log

Here we write the elapsed time reported by the benchmark.

### Initial (c830f4e)

19.483s, 19.201s, 18.849s.
