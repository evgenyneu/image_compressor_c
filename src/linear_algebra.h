#ifndef INCLUDE_LINEAR_ALGEBRA_H
#define INCLUDE_LINEAR_ALGEBRA_H


// Matrix
typedef struct
{
    // A 1D array containing values of the matrix.
    // Elements are incremented along rows.
    // For example, suppose we have a 2x3 matrix (2 rows, 3 columns):
    //
    //   |  5  12  18 |
    //   | 11   7   8 |
    //
    // The elements will be accessed the following way:
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


#endif // INCLUDE_LINEAR_ALGEBRA_H