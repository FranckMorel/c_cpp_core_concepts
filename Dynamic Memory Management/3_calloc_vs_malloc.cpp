/*
 * Topic: calloc() vs malloc()
 *
 * This example demonstrates:
 * - differences between malloc() and calloc()
 * - memory initialization behavior
 * - allocation syntax
 * - when calloc() can be useful
 *
 * Embedded relevance:
 * Understanding the difference is important because:
 * - uninitialized memory can cause bugs
 * - protocol buffers often require zero initialization
 * - deterministic startup behavior is important
 *
 * NOTE:
 * The Extra Notes section contains detailed explanations
 * of all operations shown in this example.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
     * malloc()
     *
     * Allocates memory but does NOT initialize it.
     */

    int *mallocArray = (int *)malloc(5 * sizeof(int));

    if (mallocArray == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("malloc() contents:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", mallocArray[i]);
    }

    printf("\n\n");

    /*
     * calloc()
     *
     * Allocates memory and initializes every byte to 0.
     */

    int *callocArray = (int *)calloc(5, sizeof(int));

    if (callocArray == NULL)
    {
        printf("calloc failed\n");

        free(mallocArray);
        return 1;
    }

    printf("calloc() contents:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", callocArray[i]);
    }

    printf("\n\n");

    /*
     * Modify values.
     */

    for (int i = 0; i < 5; i++)
    {
        callocArray[i] = (i + 1) * 100;
    }

    printf("Modified calloc array:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", callocArray[i]);
    }

    printf("\n");

    free(mallocArray);
    free(callocArray);

    mallocArray = NULL;
    callocArray = NULL;

    return 0;
}

/*
 * Extra Notes
 *
 * malloc():
 *
 * malloc(n * sizeof(type))
 *
 * - allocates memory
 * - memory is NOT initialized
 * - contents are undefined
 *
 *
 * calloc():
 *
 * calloc(n, sizeof(type))
 *
 * - allocates memory
 * - every byte initialized to 0
 *
 *
 * Example:
 *
 * malloc(5 * sizeof(int))
 *
 * calloc(5, sizeof(int))
 *
 * both allocate memory for 5 integers
 *
 *
 * Common use cases for calloc():
 *
 * - buffers
 * - lookup tables
 * - structs
 * - communication packets
 * - state machines
 *
 *
 * Every successful malloc() or calloc()
 * must eventually be matched with free().
 */
