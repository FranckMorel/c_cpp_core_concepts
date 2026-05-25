/*
 * Topic: Multidimensional Arrays
 *
 * This example demonstrates:
 * - memory layout of 2D arrays
 * - pointer access for multidimensional arrays
 * - row-based memory organization
 * - dereferencing multidimensional arrays
 *
 * Embedded relevance:
 * Multidimensional arrays are commonly used in:
 * - image buffers
 * - communication frames
 * - lookup tables
 * - sensor matrices
 * - graphics systems
 */

#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
                        {2, 3, 6},
                        {4, 5, 8}
                        };

    /*
     * Pointer to the first row of the array.
     *
     * matrix decays to:
     * int (*)[3]
     */
    int (*ptr)[3] = matrix;

    printf("Address of 1st row: %p\n", (void *)matrix);    // or (void*)&matrix
    printf("Address of 2nd row: %p\n", (void *)matrix[1]); // or (void*)&matrix[1]

    /*
 * Important difference:
 *
 * matrix
 * -> decays to a pointer to the first row
 * -> type: int (*)[3]
 * -> equivalent to &matrix[0]
 *
 * &matrix
 * -> pointer to the entire 2D array
 * -> type: int (*)[2][3]
 *
 * Address note:
 * The first row starts at the same memory address as the entire array,
 * and the first element starts at that same address as well.
 *
 * Therefore, matrix, &matrix and &matrix[0][0] may print the same
 * numeric address.
 *
 * However, their pointer types are different, so pointer arithmetic
 * behaves differently.
 *
 * matrix + 1
 * -> moves to the next row
 *
 * &matrix + 1
 * -> moves past the entire 2D array
 */


    /*
     * Access elements using pointer dereferencing.
     */
    printf("matrix[0][0]: %d\n", *(*matrix + 0) );
    printf("matrix[0][1]: %d\n", *(*matrix + 1) );

    printf("matrix[1][0]: %d\n", *(*(matrix + 1)) );
    printf("matrix[1][2]: %d\n", *(*(matrix + 1) + 2));


    /*
     * Access elements through row pointer.
     */
    printf("First element of first row: %d\n", *ptr[0]);
    printf("Last element of first row: %d\n", (*ptr)[2]);
    printf("Second element of second row: %d\n", (*(ptr+1))[1]);

    return 0;
}

/* Extra Notes
matrix == &matrix[0] -> Address of 1st row
*matrix == &matrix[0][0]  -> Address of 1st Element , 1st row
*(*matrix) == matrix[0][0] -> 1st Element , 1st row

for int (*ptr)[3] = matrix
ptr == matrix = &matrix[0] -> Adress of 1st row
*ptr == *matrix = &matrix[0][0] -> Adress of 1st Element, 1st row
*(*ptr) == *(*matrix) == matrix[0][0] -> 1st Element , 1st row

!!!! When using ptr you must make sure this form *(ptr)[3] ist respected
    *(ptr+i)[j] is not equals to (*(ptr + i))[j]

    correct form:
    (*(ptr + i))[j] or *(*(ptr + i) + j)

*/
