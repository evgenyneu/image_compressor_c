/*
Singular value decomposition and expansion.
*/

#ifndef INCLUDE_SVD_H
#define INCLUDE_SVD_H

#include "linear_algebra.h"


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




#endif // INCLUDE_SVD_H