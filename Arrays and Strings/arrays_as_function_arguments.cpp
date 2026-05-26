/*
 * Topic: Arrays as Function Arguments
 *
 * This example demonstrates:
 * - how arrays are passed to functions
 * - why arrays decay to pointers
 * - why array size information is lost inside functions
 * - how functions can modify the original array
 *
 * Embedded relevance:
 * Arrays are frequently passed to embedded driver functions for:
 * - UART buffers
 * - SPI transfers
 * - ADC sample buffers
 * - DMA memory regions
 * - sensor data processing
 */

#include <stdio.h>

void print_array(int *array, int size)
{
    /*
     * Important:
     *
     * Inside a function, the parameter "array" is not the original array.
     * It is only a pointer to the first element.
     *
     * Therefore, sizeof(array) returns the size of a pointer,
     * not the size of the full array.
     */

    printf("Inside print_array():\n");
    printf("sizeof(array): %zu bytes\n", sizeof(array));
    printf("Received size: %d elements\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("\n");
}

void increment_elements(int *array, int size)
{
    /*
     * The function receives a pointer to the original array data.
     * Therefore, modifying array[i] changes the original array in main().
     */

    for (int i = 0; i < size; i++)
    {
        array[i]++;
    }
}

int calculate_sum(int array[], int size)
{
    /*
     * int array[] and int *array are equivalent in function parameters.
     * The compiler treats both as pointers.
     */

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main(void)
{
    int values[] = {2, 4, 6, 8, 10};

    int size = sizeof(values) / sizeof(values[0]);

    printf("Inside main():\n");
    printf("sizeof(values): %zu bytes\n", sizeof(values));
    printf("Number of elements: %d\n\n", size);

    print_array(values, size);

    increment_elements(values, size);

    printf("After increment_elements():\n");
    print_array(values, size);

    int total = calculate_sum(values, size);

    printf("Sum of elements: %d\n", total);

    /*
     * Important:
     *
     * When values is passed to a function:
     *
     * values -> &values[0]
     *
     * The array decays to a pointer to the first element.
     * The function does not know the original array size unless
     * the size is passed explicitly.
     */

    return 0;
}
