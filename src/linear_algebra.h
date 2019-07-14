/*
Matrix manipulation: multiplication, addition, transpose etc.
*/

#ifndef INCLUDE_LINEAR_ALGEBRA_H
#define INCLUDE_LINEAR_ALGEBRA_H

// Used to check if a number is close to zero
#define ALMOST_ZERO 1e-20

// Matrix
typedef struct
{
    // A 1D array containing values of the matrix.
    // Elements are incremented along rows.
    // For example, suppose we have a 2 by 3 matrix (2 rows, 3 columns):
    //
    //   |  5  12  18 |
    //   | 11   7   8 |
    //
    // Then the elements are stored like this:
    //   data[0] is  5
    //   data[1] is 12
    //   data[2] is 18
    //   data[3] is 11
    //   data[4] is  7
    //   data[5] is  8
    //
    double *data;

    // Number of rows
    int row_num;

    // Number of columns
    int col_num;
} Matrix;


/*

Allocate a new matrix.

Inputs:
-------

row_num : number of rows.

col_num : number of columns.


Outputs:
-------

Returns : a new matrix.

*/
Matrix *new_matrix(int row_num, int col_num);

/*

Allocate a new matrix based on the given data array.
A new block of memory is allocated in Matrix->data and then elements
are copied to it from the supplied `array`.

Inputs:
-------

array : A 1D array containing values of the matrix.

row_num : number of rows.

col_num : number of columns.


Outputs:
-------

Returns : a new matrix.

*/
Matrix *new_matrix_from_array(double *array, int row_num, int col_num);

/*

Free matrix memory, both for the `matrix->data` and for the `matrix` structure.

Inputs:
-------

matrix : a matrix.


*/
void free_matrix(Matrix *matrix);

/*

Adds two matrices and returns the result.

Inputs:
-------

matrix1, matrix2 : Two matrices that will be added.


Outputs:
-------

Returns : a new matrix, which is a sum of matrix1 and matrix2.

*/
Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2);


/*

Multiply two matrices and return the result.

Inputs:
-------

matrix1, matrix2 : Two matrices that will be multiplied.


Outputs:
-------

Returns : a new matrix, which is the product of matrix1 and matrix2.

*/
Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2);


/*

Multiply a matrix with a vector.

Inputs:
-------

matrix: A matrix.

vector: A vector (a matrix with a single column).


Outputs:
-------

Returns : a new n-by-1 matrix, which is the result of the product of `matrix` with `vector`.

*/
Matrix *multiply_matrix_with_vector(Matrix *matrix, Matrix *vector);


/*

Multiply a symmetric matrix with a vector.

Inputs:
-------

matrix: A symmetric matrix with only upper triangular part specified.

vector: A vector (a matrix with a single column).


Outputs:
-------

Returns : a new n-by-1 matrix, which is the result of the product of `matrix` with `vector`.

*/
Matrix *multiply_upper_symmetric_matrix_with_vector(Matrix *matrix, Matrix *vector);


/*

Multiply `matrix` with the `number` and update `matrix`.

Inputs:
-------

matrix : a matrix.

number : a number.

*/
void multiply_matrix_with_a_number(Matrix *matrix, double number);


/*

Transposes the matrix.

Inputs:
-------

matrix : a matrix.


Outputs:
-------

Returns : a tranposed matrix.

*/
Matrix *transpose_matrix(Matrix *matrix);


/*

Calculates the dot product of two n by 1 matrices.

Inputs:
-------

matrix1, matrix2 : matrices with size n by 1 (n rows, one column).


Outputs:
-------

Returns : result of the dot product.

*/
double dot_product(Matrix *matrix1, Matrix *matrix2);

/*

Calculates the length of a vector passed in an n by 1 matrix.

Inputs:
-------

matrix : matrix with size n by 1 (n rows, one column).


Outputs:
-------

Returns : length of the vector

*/
double norm(Matrix *matrix);


/*

Returns the upper triangular part of Gramian of `matrix`.

Inputs:
-------

matrix : a matrix.


Outputs:
-------

Returns : Gramian of `matrix`. This symmetric matrix has values only in its upper triangular part. The values in the strictly lower triangular part are not initialized.

*/
Matrix *gramian(Matrix *matrix);


#endif // INCLUDE_LINEAR_ALGEBRA_H