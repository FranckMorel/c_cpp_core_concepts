/*
 * Topic: Array Basics
 *
 * This example demonstrates:
 * - how arrays store elements in contiguous memory
 * - how array indexing works
 * - relationship between array indexing and pointer arithmetic
 *
 * Embedded relevance:
 * Arrays are commonly used in embedded systems for:
 * - sensor buffers
 * - communication frames
 * - lookup tables
 * - ADC sample storage
 * - fixed-size data buffers
 */

#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    int size = sizeof(values) / sizeof(values[0]);

    printf("Array elements:\n");

    for (int i = 0; i < size; i++)
    {
        printf("values[%d] = %d\n", i, values[i]);
    }

    printf("\nMemory addresses:\n");

    for (int i = 0; i < size; i++)
    {
        printf("Address of values[%d]: %p\n", i, (void *)&values[i]);
    }


    printf("Array elements:\n");

    for (int i = 0; i < size; i++)
    {
        printf("values[%d] = %d\n", i, values[i]);
    }
    /*
     * Array indexing and pointer arithmetic are equivalent:
     *
     * values[i] == *(values + i)
     */

    printf("\nAccess using pointer arithmetic:\n");

    for (int i = 0; i < size; i++)
    {
        printf("*(values + %d) = %d\n", i, *(values + i));
    }

    return 0;
}
