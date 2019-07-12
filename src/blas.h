extern void dgemm_(char*, char*, int*, int*,int*, double*, double*, int*, double*, int*, double*, double*, int*);

// dgemm_ expects matrices a, b and c in column-major order.
// For matrices in row-major we can use transpose property (A B)^T = B^T A^T.
// Based on https://www.christophlassner.de/using-blas-from-c-with-row-major-data.html
#define DGEMM_ROWMAJOR(trans_a, trans_b, m, n, k, alpha, a, b, beta, c) \
        dgemm_(trans_b, trans_a, n, m, k, alpha, b, n, a, k, beta, c, n)