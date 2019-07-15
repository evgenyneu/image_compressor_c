# An image compression program written in C

This is a C program I wrote for fun to apply linear algebra theory I learned in Monash uni. The code uses singular value expansion method to reduce the size of an image. Here is are compression examples, featuring my cat Marmite.

<a href="https://youtu.be/7JXdEilZ2cE" target=”_blank”><img alt="Video of the compressed image" width="400px" src="images/youtube/youtube_thumbnail4.jpg"></a>

<img alt="Image compressed using single value expansion" width="400px" src="images/compressed/compression_animated.gif">

## Setup

### 1. Install GCC

In order to compile the program, you will need the GCC, a C compiler. Check if it's installed with the command that prints its version.

```
gcc -v
```

If you get an error, install GCC on your system.

### 2. Install OpenBLAS library

Follow [these instructions](doc/install_open_blas.md) to install OpenBLAS library.


### 3. Download the source code

Next, download the source code of the compressor (requires [git](https://git-scm.com)):

```
git clone https://github.com/evgenyneu/image_compressor_c.git
cd image_compressor_c
```

### 4. Build the program

Finally, build the program:

```
make
```

This will create the executable file `/build/compressor`.


## Usage

Compress an image file [marmite.jpg](marmite.jpg) using ten terms of the singular value expansion and five iterations of the power method:

```
./build/compressor --terms=10 --iterations=5 marmite.jpg compressed.jpg
```

It creates an image named `compressed.jpg` that looks like this:

![Singular value expansion compression with 10 terms](images/marmite_500x500_10_terms_25.0x_compression.jpg)

You can experiment with the `--terms` and `--iterations` options and see how it affects the image quality and compression ratio.


### Available options

```
compressor [--help] [--terms=10] [--iterations=5] IMAGE OUTPUT

IMAGE :  path to the image to compress
OUTPUT :  path to the compressed image that will be created
--terms :  number of terms in the singular value expansion
--iterations :  number of iterations of the power method
--notext :  no annotation on the image
--benchmark :  run the benchmark to measure compression performance,
               no other options are needed for the benchmark
--help :  show this message
```



## Run unit tests 

```
make test
```

## The unlicense

This work is in [public domain](LICENSE).


## Compression results

### Original uncompressed image

![Uncompressed image](images/marmite_1000x1000.jpg)

### Compressed images

The program produced the following compressed images:

![1 term compression](images/compressed/marmite_001_terms.jpg)

![2 term compression](images/compressed/marmite_002_terms.jpg)

![3 term compression](images/compressed/marmite_003_terms.jpg)

![4 term compression](images/compressed/marmite_004_terms.jpg)

![5 term compression](images/compressed/marmite_005_terms.jpg)

![6 term compression](images/compressed/marmite_006_terms.jpg)

![7 term compression](images/compressed/marmite_007_terms.jpg)

![8 term compression](images/compressed/marmite_008_terms.jpg)

![9 term compression](images/compressed/marmite_009_terms.jpg)

![10 term compression](images/compressed/marmite_010_terms.jpg)

![11 term compression](images/compressed/marmite_011_terms.jpg)

![12 term compression](images/compressed/marmite_012_terms.jpg)

![13 term compression](images/compressed/marmite_013_terms.jpg)

![14 term compression](images/compressed/marmite_014_terms.jpg)

![15 term compression](images/compressed/marmite_015_terms.jpg)

![16 term compression](images/compressed/marmite_016_terms.jpg)

![17 term compression](images/compressed/marmite_017_terms.jpg)

![18 term compression](images/compressed/marmite_018_terms.jpg)

![19 term compression](images/compressed/marmite_019_terms.jpg)

![20 term compression](images/compressed/marmite_020_terms.jpg)

![25 term compression](images/compressed/marmite_025_terms.jpg)

![30 term compression](images/compressed/marmite_030_terms.jpg)

![35 term compression](images/compressed/marmite_035_terms.jpg)

![40 term compression](images/compressed/marmite_040_terms.jpg)

![45 term compression](images/compressed/marmite_045_terms.jpg)

![50 term compression](images/compressed/marmite_050_terms.jpg)

![60 term compression](images/compressed/marmite_060_terms.jpg)

![70 term compression](images/compressed/marmite_070_terms.jpg)

![80 term compression](images/compressed/marmite_080_terms.jpg)

![90 term compression](images/compressed/marmite_090_terms.jpg)

![100 term compression](images/compressed/marmite_100_terms.jpg)

![120 term compression](images/compressed/marmite_120_terms.jpg)

![150 term compression](images/compressed/marmite_150_terms.jpg)

![180 term compression](images/compressed/marmite_180_terms.jpg)

![200 term compression](images/compressed/marmite_200_terms.jpg)

![300 term compression](images/compressed/marmite_300_terms.jpg)

![400 term compression](images/compressed/marmite_400_terms.jpg)

![500 term compression](images/compressed/marmite_500_terms.jpg)

