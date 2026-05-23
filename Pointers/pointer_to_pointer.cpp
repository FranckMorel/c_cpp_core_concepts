/*
 * Topic: Pointer to Pointer
 *
 * This example demonstrates:
 * - how a pointer can store the address of another pointer
 * - double dereferencing
 * - accessing and modifying data through multiple pointer levels
 *
 * Embedded relevance:
 * Pointer-to-pointer concepts appear in:
 * - dynamic memory management
 * - communication stacks
 * - driver interfaces
 * - RTOS APIs
 * - complex buffer handling
 */

#include <stdio.h>

int main(void)
{
    int value = 50;

    // Pointer to an integer
    int *ptr = &value;

    // Pointer to pointer
    int **doublePtr = &ptr;

    printf("Value: %d\n", value);
    printf("Address of Value: %p\n", (void *)&value);

    printf("Pointer ptr stores: %p\n", (void*)ptr); // or (void*)&value
    printf("Address of pointer ptr: %p\n", (void *)&ptr);

    printf("Pointer doublePtr stores: %p\n", (void *)doublePtr); // or (void*)&ptr
    printf("Address of pointer doublePtr: %p\n\n", (void *)&doublePtr);


    // Dereferencing levels
    printf("Single dereference *ptr: %d\n", *ptr);
    printf("Double dereference **doublePtr: %d\n\n", **doublePtr);

    // Modify value through pointer-to-pointer
    **doublePtr = 100;

    printf("Modified value: %d\n", value);

    return 0;

}
