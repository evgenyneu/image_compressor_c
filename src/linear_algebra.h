#ifndef INCLUDE_LIEAR_ALGEBRA_H
#define INCLUDE_LIEAR_ALGEBRA_H


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

Free matrix memory, both for the `matrix->data` and for the `matrix` structure.

Inputs:
-------

matrix : a matrix.

*/
void free_matrix(Matrix *matrix);

#endif // INCLUDE_LIEAR_ALGEBRA_H