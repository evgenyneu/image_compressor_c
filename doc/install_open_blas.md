# Installing OpenBLAS on Mac and Ubuntu

[OpenBLAS](https://en.wikipedia.org/wiki/OpenBLAS) is a library that performs linear algebra operations like matrix multiplication. The code is optimized for individual processor types to decrease calculation time. In our benchmark that multiplied two 1000 by 1000 matrices OpenBLAS was 55 times faster than our own code containing three nested loops.

Benchmark results: [multiply_1000_by_1000_matrices.xlsx](/benchmark/multiply_1000_by_1000_matrices.xlsx).

Follow the instructions below to install OpenBLAS library.

## Download the source code


```
git clone https://github.com/xianyi/OpenBLAS.git
cd OpenBLAS
```


## Build the library

```
make
```


## Install the library

```
sudo make install
```

The library and header files will be copied to `/opt/OpenBLAS` directory.


## Cleanup: remove OpenBLAS source code

```
cd ..
rm -rf OpenBLAS
```
