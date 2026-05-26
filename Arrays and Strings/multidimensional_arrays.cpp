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
    //2D array
    int matrix[2][3] = {
                        {2, 3, 6},
                        {4, 5, 8}
                        };

    // 3D array -> see 3D array notes at the end of this file
    int cube[2][3][4] = {{{2, 1, 6, 7}, {6, 4, 2, 1}, {5, 6, 8, 1}},
                         {{3, 1, 9, 8}, {2, 3, 6, 7}, {4, 5, 8, 3}}
                        };
    /*
     * Pointer to the first row of the array.
     *
     * matrix decays to:
     * int (*)[3]
     */

    int (*ptr)[3] = matrix;

    printf("Address of first row: %p\n", (void *)&matrix[0]);
    printf("Address of second row: %p\n\n", (void *)&matrix[1]);

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
     * The first row starts at the same numeric memory address
     * as the entire array, and the first element starts there as well.
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

    printf("matrix[0][0]: %d\n", *(*matrix + 0));
    printf("matrix[0][1]: %d\n", *(*matrix + 1));

    printf("matrix[1][0]: %d\n", *(*(matrix + 1)));
    printf("matrix[1][2]: %d\n\n", *(*(matrix + 1) + 2));

    /*
     * Access elements through row pointer.
     */
    printf("First element of first row: %d\n", (*ptr)[0]);
    printf("Last element of first row: %d\n", (*ptr)[2]);
    printf("Second element of second row: %d\n", (*(ptr + 1))[1]);

    /*
     * Extra notes:
     *
     * matrix == &matrix[0]
     * -> address of first row
     *
     * *matrix == &matrix[0][0]
     * -> address of first element in first row
     *
     * *(*matrix) == matrix[0][0]
     * -> first element in first row
     *
     *
     * For:
     * int (*ptr)[3] = matrix;
     *
     * ptr == matrix == &matrix[0]
     * -> address of first row
     *
     * *ptr == *matrix == &matrix[0][0]
     * -> address of first element in first row
     *
     * *(*ptr) == *(*matrix) == matrix[0][0]
     * -> first element in first row
     *
     *
     * Correct access forms:
     *
     * (*(ptr + i))[j]
     * *(*(ptr + i) + j)
     *
     * Wrong / misleading form:
     *
     * *(ptr + i)[j]
     *
     * because [] has higher precedence than *.
     */

    /*
    * 3D Array Notes
    *
    * For:
    *
    * int cube[2][3][4];
    *
    * cube
    * -> decays to pointer to first 2D block
    * -> type: int (*)[3][4]
    *
    * cube == &cube[0]
    * -> address of first 2D block
    *
    * *cube
    * -> first 2D block
    * -> usually decays to &cube[0][0]
     *
    * *(*cube)
    * -> first row of first block
    * -> usually decays to &cube[0][0][0]
    *
    * *(*(*cube))
    * -> first element of first row in first block
    * -> equivalent to cube[0][0][0]
    *
    *
    * For:
    *
    * int (*ptr)[3][4] = cube;
     *
     * ptr == cube == &cube[0]
     * -> address of first 2D block
     *
    * *ptr == *cube == &cube[0][0]
    * -> address of first row in first block
    *
    * *(*ptr) == *(*cube) == &cube[0][0][0]
    * -> address of first element
    *
    * *(*(*ptr)) == cube[0][0][0]
    * -> first element
    *
    *
    * Correct access forms:
    *
    * cube[i][j][k]
    *
    * *(*(*(cube + i) + j) + k)
    *
    * *(*(*(ptr + i) + j) + k)
    */

    return 0;
}
