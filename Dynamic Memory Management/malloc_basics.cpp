/*
 * Topic: malloc Basics
 *
 * This example demonstrates:
 * - allocating memory with malloc()
 * - checking for allocation failure
 * - accessing dynamically allocated memory
 * - releasing memory with free()
 *
 * Embedded relevance:
 * Dynamic allocation is sometimes used for:
 * - communication buffers
 * - packet storage
 * - dynamic data structures
 * - protocol implementations
 *
 * In many embedded systems dynamic allocation is avoided
 * because memory usage becomes harder to predict.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
     * Allocate memory for one integer.
     */

    int *ptr = (int *)malloc(sizeof(int));

    /*
     * Always verify allocation success.
     */

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /*
     * Write data into allocated memory.
     */

    *ptr = 42;

    printf("Value: %d\n", *ptr);
    printf("Address: %p\n", (void *)ptr);

    /*
     * Allocate memory for an array.
     */

    int *array = (int *)malloc(5 * sizeof(int));

    if (array == NULL)
    {
        printf("Array allocation failed\n");

        free(ptr);
        return 1;
    }

    /*
     * Initialize array.
     */

    for (int i = 0; i < 5; i++)
    {
        array[i] = (i + 1) * 10;
    }

    printf("\nArray contents:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    /*
     * Important:
     *
     * malloc() does NOT initialize memory.
     *
     * If you read memory before writing to it,
     * the value is undefined.
     */

    /*
     * Release memory.
     */

    free(ptr);
    free(array);

    /*
     * Good practice:
     */

    ptr = NULL;
    array = NULL;

    return 0;
}

/*
 * Extra Notes
 *
 * malloc(size)
 * -> allocates size bytes on the heap
 *
 * malloc(n * sizeof(type))
 * -> allocates memory for n elements
 *
 * malloc() returns:
 * -> valid address on success
 * -> NULL on failure
 *
 * Memory returned by malloc():
 * -> contains garbage values
 * -> is NOT initialized
 *
 * Every malloc() should have a matching free()
 *
 * After free(ptr):
 * -> ptr becomes a dangling pointer
 *
 * Recommended:
 * free(ptr);
 * ptr = NULL;
 */
