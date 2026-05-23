/*
 * Topic: Pointer Basics
 *
 * This example demonstrates:
 * - how to store the address of a variable in a pointer
 * - how to access a value through a pointer
 * - how modifying data through a pointer affects the original variable
 *
 * Embedded relevance:
 * Pointers are essential for memory-mapped registers, buffers,
 * peripheral access and low-level driver development.
 */

#include <stdio.h>

int main(void)
{
    int value = 10;

    // A pointer stores the memory address of another variable.
    int *ptr = &value;

    printf("Original value: %d\n", value);
    printf("Address of value: %p\n", (void *)&value);

    printf("Pointer stores address: %p\n", (void *)ptr);
    printf("Value accessed through pointer: %d\n", *ptr);

    // Modify the original variable through the pointer.
    *ptr = 25;

    printf("Modified value: %d\n", value);

    return 0;
}
