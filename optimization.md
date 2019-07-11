# Optimizing performance

We want to make the program run faster. To measure performance we run the following benchmark on the same computer

```
./build/compressor --benchmark
```

with compiler options

```
CXX = gcc
CXX_FLAGS = -O1 -g -std=c99 -Wall -Wextra -Wshadow -Wwrite-strings -Werror-implicit-function-declaration -Wundef -Wpointer-arith -Waggregate-return  -Wswitch-default -Wunreachable-code -Wformat=2 -Wmissing-prototypes -Wstrict-prototypes -Wconversion
```

It will produce the following output:


```
Compresssing images/marmite_500x500.jpg to images/marmite_output_500x500.bmp
Terms: 30
Iterations: 5
Done
Compression time: 19.400999 s
```

## Benchmark log

Here we write the "compression time" reported by the benchmark.

### Initial (c830f4e)

19.483s, 19.201s, 18.849s.
