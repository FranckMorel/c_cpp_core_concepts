/*
 * Topic: Pointer Arithmetic
 *
 * This example demonstrates:
 * - how pointer arithmetic works
 * - how pointers move through memory
 * - relationship between array elements and addresses
 *
 * Embedded relevance:
 * Pointer arithmetic is heavily used in:
 * - buffer handling
 * - DMA memory access
 * - communication protocols
 * - low-level memory manipulation
 */

#include <stdio.h>

int main(void)
{
    int numbers[4] = {10, 20, 30, 40};

    // Pointer to the first element of the array
    int *ptr = numbers;

    printf("Base address: %p\n\n", (void *)ptr);

    for (int i = 0; i < 4; i++)
    {
        printf("Element %d\n", i);

        // Address of current element
        printf("Address: %p\n", (void *)(ptr + i));

        // Value of current element
        printf("Value: %d\n\n", *(ptr + i));
    }

    /*
     * Pointer arithmetic:
     *
     * ptr + 1 moves to the next integer in memory.
     * Since sizeof(int) is typically 4 bytes,
     * the address increases by 4 bytes.
     */

    return 0;
}
