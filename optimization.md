# Optimizing performance

We want to make the program run faster. To measure performance we run the following benchmark on the same computer

> time ./build/compressor images/marmite_500x500.jpg ~/Downloads/compressed.bmp --terms=30 --iterations=5

with compiler options

> CXX = gcc
> CXX_FLAGS = -O1 -g -std=c99 -Wall -Wextra -Wshadow -Wwrite-strings -Werror-implicit-function-declaration -Wundef -Wpointer-arith -Waggregate-return  -Wswitch-default -Wunreachable-code -Wformat=2 -Wmissing-prototypes -Wstrict-prototypes -Wconversion

## Benchmark log

Here we write the `user` elapsed time from the output of the `time` command.

### Initial

19.483s, 19.201s, 18.849s.
