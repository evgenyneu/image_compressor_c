/*
Singular value decomposition and expansion.
*/

#ifndef INCLUDE_SVD_H
#define INCLUDE_SVD_H

#include "linear_algebra.h"

// Contains element of the singular value decomposition UΣV^T
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

Free memory of SVD data.

Inputs:
-------

svd_data :SVD data.

*/
void free_svd(SVD *svd_data);


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

Returns: singular value decomposition data for the `matrix`.

*/
SVD *svd(Matrix *matrix, int max_eigenvalues, int iterations);


/*

Performs singular value expansion by reconstructing the original `matrix`
    from its SVD UΣV^T.

Inputs:
-------

svd_data : singular value decomposition data created by the `svd` function that contains singular value decomposition.

Outputs:
-------

Returns: a matrix, which is the result of the singular value expansion.

*/
Matrix *singular_value_expansion(SVD *svd_data);


#endif // INCLUDE_SVD_H