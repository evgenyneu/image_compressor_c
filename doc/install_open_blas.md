# Installing OpenBLAS on Mac and Ubuntu

[OpenBLAS](https://en.wikipedia.org/wiki/OpenBLAS) is a library that performs linear algebra operations like matrix multiplication. The code is optimized for individual processor types to decrease calculation time. In our benchmark that multiplied two 1000 by 1000 matrices OpenBLAS was 55 times faster than our own code.

Benchmark results: [benchmark.xlsx](/benchmark/benchmark.xlsx).


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