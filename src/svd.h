/*
Singular value decomposition and expansion.
*/

#ifndef INCLUDE_SVD_H
#define INCLUDE_SVD_H

#include "linear_algebra.h"

// Contains element from the singular value decomposition UΣV^T
typedef struct
{
    // Number of elements in `u_vectors`, `singular_values` and `v_vectors` arrays.
    int elements;

    // Array of m by 1 matrices, the column vectors of U.
    Matrix **u_vectors;

    // Corresponding singular value of `matrix`, which are the diagonal entries of Σ matrix.
    double *singular_values;

    // Array of n by 1 matrices, the column vectors of V
    Matrix **v_vectors;
} SVD;


/*

Find the u column vector of the U matrix in the SVD UΣV^T.

Inputs:
-------

matrix : Matrix for which the SVD is calculated. Dimensions are n by m.

v : A column vector of V matrix, it is the eigenvector of the Gramian of `matrix`. Dimensions are m by 1.

singular_value : A singular value of `matrix` corresponding to the `v` vector.


Outputs:
-------

Returns : u column vector of the U matrix in the SVD. Dimensions are n by 1.

*/
Matrix *find_u_from_v(Matrix *matrix, Matrix *v, double singular_value);


/*

Performs reduced singular value decomposition of the matrix:
    matrix = UΣV^T.

Inputs:
-------

matrix : an m by n  matrix.

max_eigenvalues : Maximum number of non-zero eigenvalues to calculate.

iterations : The number of iterations of the power method.

Outputs:
-------

elements : number of elements in `u_vectors`, `singular_values` and `v_vectors` arrays.

u_vectors : array of m by 1 matrices, the column vectors of U.

singular_values :  corresponding singular value of `matrix`,
                which are the diagonal entries of Σ matrix.

v_vectors :  array of n by 1 matrices, the column vectors of V.

*/

SVD *svd(Matrix *matrix, int max_eigenvalues, int iterations);


#endif // INCLUDE_SVD_H