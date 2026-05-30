/*
 * Topic: Double Free
 *
 * This example demonstrates:
 * - what a double free is
 * - why freeing the same memory twice is dangerous
 * - how setting a pointer to NULL after free() can help
 *
 * Embedded relevance:
 * Double free bugs can corrupt the heap and cause:
 * - random crashes
 * - corrupted data
 * - unpredictable firmware behavior
 * - hard-to-debug runtime faults
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 42;

    printf("Value before free(): %d\n", *ptr);
    printf("Address before free(): %p\n\n", (void *)ptr);

    /*
     * First free:
     *
     * This releases the heap memory.
     */
    free(ptr);

    /*
     * Dangerous:
     *
     * ptr still contains the old address.
     * Calling free(ptr) again would be a double free.
     *
     * The following line would cause undefined behavior:
     *
     * free(ptr);
     */

    /*
     * Safe practice:
     *
     * Set ptr to NULL after free().
     */
    ptr = NULL;

    /*
     * Calling free(NULL) is safe.
     * It does nothing.
     */
    free(ptr);

    printf("Pointer after setting to NULL: %p\n", (void *)ptr);

    return 0;
}

/*
 * Extra Notes
 *
 * Double Free:
 *
 * A double free happens when the same allocated memory block
 * is released more than once.
 *
 *
 * Example:
 *
 * int *ptr = malloc(sizeof(int));
 *
 * free(ptr);
 * free(ptr);
 *
 * The second free(ptr) is invalid because the memory block
 * has already been released.
 *
 *
 * Why is this dangerous?
 *
 * The heap allocator manages metadata internally.
 * Freeing the same block twice can corrupt that metadata.
 *
 * Result:
 * - program crash
 * - heap corruption
 * - security vulnerabilities
 * - unpredictable behavior
 *
 *
 * Important:
 *
 * free(ptr);
 *
 * does not change ptr.
 *
 * ptr still contains the old address.
 *
 *
 * Safer pattern:
 *
 * free(ptr);
 * ptr = NULL;
 *
 *
 * Why is this safer?
 *
 * free(NULL) is defined and safe.
 * It does nothing.
 *
 *
 * Memory Leak vs Dangling Pointer vs Double Free:
 *
 * Memory Leak:
 * -> allocated memory is not released
 *
 * Dangling Pointer:
 * -> pointer refers to invalid memory
 *
 * Double Free:
 * -> same memory block is released more than once
 */
