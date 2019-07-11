# Benchmark

We want to optimize the program in order to make it faster. In order to do this we need to measure the time it takes for the program to compress an image. This compression time is reported by running the following command:

```
./build/compressor --benchmark
```

Before running the benchmark we replace CXX and CXX_FLAGS in the [Makefile](Makefile) with the following:

```
CXX = gcc
CXX_FLAGS = -O1 -g -std=c99 -Wall -Wextra -Wshadow -Wwrite-strings -Werror-implicit-function-declaration -Wundef -Wpointer-arith -Waggregate-return  -Wswitch-default -Wunreachable-code -Wformat=2 -Wmissing-prototypes -Wstrict-prototypes -Wconversion
```

Then we rebuild the program

```
make clean
make
```

The benchmark shows the following output:


```
Compresssing images/marmite_500x500.jpg to images/marmite_output_500x500.bmp
Terms: 30
Iterations: 5
Done
Compression time: 19.400999 s
```

## Benchmark history

Here we write the "compression time" reported by the benchmark. The text like `c830f4e` in the brackets indicates the GIT commit that was used to run the benchmark.

The benchmark was run on MacBook Pro (Retina, 13-inch, Late 2012) computer with 2.5 GHz Intel Core i5 processor and 8 GB of RAM. The gcc compiler command used Apple LLVM compiler version 10.0.1.


### Initial (c830f4e)

19.483s, 19.201s, 18.849s.
