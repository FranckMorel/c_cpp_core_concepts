/*
 * File: array_decay.cpp
 * Topic: Array Decay
 *
 * This example demonstrates:
 * - how an array decays to a pointer in function calls
 * - why array size information is lost inside a function
 * - why the array size should be passed explicitly
 *
 * Embedded relevance:
 * Array decay is important for embedded systems because arrays are often
 * passed to driver functions, communication handlers and buffer-processing APIs.
 */

#include <stdio.h>

void print_array_info(int *array, int size)
{
    /*
     * Inside this function, array is only a pointer.
     * Therefore, sizeof(array) returns the size of a pointer,
     * not the size of the original array.
     */

    printf("Inside function:\n");
    printf("sizeof(array): %zu bytes\n", sizeof(array));
    printf("Received size: %d elements\n\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int main(void)
{
    int values[] = {5, 10, 15, 20};

    int size = sizeof(values) / sizeof(values[0]);

    printf("Inside main:\n");
    printf("sizeof(values): %zu bytes\n", sizeof(values));
    printf("Number of elements: %d\n\n", size);

    print_array_info(values, size);

    /*
     * Important:
     *
     * When values is passed to print_array_info(),
     * it decays to a pointer to the first element.
     *
     * values -> &values[0]
     */

    return 0;
}
