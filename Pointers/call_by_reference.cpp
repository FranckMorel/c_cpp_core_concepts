/*
 * Topic: Call by Reference using Pointers
 *
 * This example demonstrates:
 * - passing variables by reference using pointers
 * - modifying original data inside a function
 * - difference between value access and address access
 *
 * Embedded relevance:
 * Call-by-reference is widely used in embedded systems:
 * - peripheral drivers
 * - buffer handling
 * - register access
 * - communication interfaces
 * - memory-efficient function calls
 */

#include <stdio.h>

/*
 * Increment the original value
 * using its memory address.
 */
void increment(int* value)
{
    *value = *value + 1;
}

int main(void)
{
    int number = 5;

    printf("Original value: %d\n", number);

    // Pass address of variable to function
    increment(&number);

    printf("Modified value: %d\n", number);

    return 0;
}
