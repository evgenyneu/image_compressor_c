# Benchmark

We want to optimize the program in order to make it faster. In order to do this we need to measure the time it takes for the program to compress an image.

First, recompile the program with benchmarking settings:

```
make clean
make benchmark
```

Next, run the benchmark:

```
./build/compressor --benchmark
```

The benchmark shows the following output:


```
Compressing images/marmite_500x500.jpg to images/marmite_output_500x500.bmp
Terms: 30
Iterations: 5
Done
Compression time: 19.400999 s
```

We can see that compression took 19.4 seconds.


## Profiling

We can run a profiling program to see the list of functions where our program spends most of the time.


### Profiling with gprof

This profiler comes with GCC compiler. All we need to do is to add `-pg` option to the `CXX_FLAGS` variable of the [Makefile](Makefile) and rebuild the program:

```
make clean
make
```

Next, run the benchmark:

```
./build/compressor --benchmark
```

Finally, save the profile report to analysis.txt file:


```
gprof ./build/compressor gmon.out > analysis.txt
```

The `analysis.txt` file looks like this:


```
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls   s/call   s/call  name    
 98.03     13.88    13.88      897     0.02     0.02  multiply_matrices
  0.71     13.98     0.10      267     0.00     0.00  transpose_matrix
  0.71     14.08     0.10      177     0.00     0.00  add_matrices
  0.49     14.15     0.07      717     0.00     0.00  multiply_matrix_with_a_number
  0.07     14.16     0.01        1     0.01     0.01  image_to_matrix
  0.00     14.16     0.00   250517     0.00     0.00  stbi__stdio_write
  0.00     14.16     0.00   250000     0.00     0.00  stbiw__write3
```

We can see that 98% of the time is spent in `multiply_matrices` function that multiplies matrices.


### Profiling with valgrind

Install valgrind and kcachegrind on Ubuntu:

```
sudo apt install valgrind
sudo apt install kcachegrind
```

Make sure executable is compiled with the `-g` option, which saves debugging information. This option should already be included in `CXX_FLAGS` variable of the [Makefile](Makefile).

Run the profiler:

```
valgrind --tool=callgrind ./build/compressor --terms=100 images/test_100x100.jpg benchmark.jpg
```

View results:

```
kcachegrind callgrind.out.*
```

![Profiling result from valgrind](/images/valgrind.png)

We can see that most of the time is spent in `multiply_matrices` function.


## Benchmark history

Here we write the "compression time" reported by the benchmark. The text like `c830f4e` in the brackets indicates the GIT commit that was used to run the benchmark.

The benchmark was run on MacBook Pro (Retina, 13-inch, Late 2012) computer with 2.5 GHz Intel Core i5 processor and 8 GB of RAM. The gcc compiler command used Apple LLVM compiler version 10.0.1.


### Initial (c830f4e)

19.483s, 19.201s, 18.849s.

