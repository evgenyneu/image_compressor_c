/*
Calculate the dominant eigenvalue and eigenvector of a matrix using the power method.
*/


#ifndef INCLUDE_POWER_METHOD_H
#define INCLUDE_POWER_METHOD_H

#include "linear_algebra.h"

/*

Calculates the dominant eigenvalue and a dominant unit eigenvector
of a symmetric matrix using the power method.

Inputs:
-------

matrix : a symmetric matrix.

iterations : number of iterations of the power method.


Outputs:
-------

eigenvalue : the dominant eigenvalue.

Returns : eigenvector corresponding to the dominant eigenvalue. Return NULL if dominant eigenvalue is zero.

*/
Matrix *dominant_eigen_system(Matrix *matrix, int iterations, double *eigenvalue);

#endif // INCLUDE_POWER_METHOD_H