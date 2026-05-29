/*
 * File: realloc_example.cpp
 * Topic: realloc()
 *
 * This example demonstrates:
 * - resizing dynamically allocated memory
 * - growing an existing array
 * - preserving existing data
 * - handling realloc() safely
 *
 * Embedded relevance:
 * Dynamic resizing is sometimes used for:
 * - communication buffers
 * - packet storage
 * - logging systems
 *
 * In many embedded systems realloc() is avoided because
 * memory usage and execution time become less predictable.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
     * Allocate memory for 3 integers.
     */

    int *array = (int *)malloc(3 * sizeof(int));

    if (array == NULL)
    {
        printf("Initial allocation failed\n");
        return 1;
    }

    /*
     * Initialize array.
     */

    for (int i = 0; i < 3; i++)
    {
        array[i] = (i + 1) * 10;
    }

    printf("Original array:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");
    printf("Address of original array: %p\n", (void *)array);
    printf("\n\n");

    /*
     * Increase array size.
     *
     * Old size: 3 integers
     * New size: 6 integers
     */

    int *temp = (int *)realloc(array, 6 * sizeof(int));

    if (temp == NULL)
    {
        printf("Reallocation failed\n");

        free(array);
        return 1;
    }

    /*
     * realloc() succeeded.
     */

    array = temp;

    /*
     * Initialize new elements.
     */

    for (int i = 3; i < 6; i++)
    {
        array[i] = (i + 1) * 10;
    }

    printf("Expanded array:\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");

    /*
     * Address may change.
     */

    printf("Current address: %p\n", (void *)array);

    /*
     * Release memory.
     */

    free(array);
    array = NULL;

    return 0;
}

/*
 * Extra Notes
 *
 * realloc(ptr, new_size)
 *
 * -> resizes existing allocation
 *
 * Possible outcomes:
 *
 * 1. Sufficient free space exists immediately after the current block
 *  -> block expanded in place
 *  -> same address returned
 *
 * 2. No sufficient free space exists after the current block
 *   -> block moved
 *   -> new address returned
 *
 * IMPORTANT:
 *
 * if you allocate memory like this:
 * int *ptr = (int *)malloc(...);
 * Never do:
 * ptr = realloc(ptr, new_size); directly because if realloc() fails,
 *
 * NULL is returned and the original pointer is lost.
 *
 *
 * Safer:
 *
 * temp = realloc(ptr, new_size);
 *
 * if(temp != NULL)
 * {
 *     ptr = temp;
 * }
 *
 *
 * New memory obtained through realloc()
 * is NOT initialized.
 */
