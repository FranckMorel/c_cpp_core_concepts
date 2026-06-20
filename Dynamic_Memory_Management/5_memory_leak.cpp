/*
 * Topic: Memory Leak
 *
 * This example demonstrates:
 * - how memory leaks occur
 * - why losing a heap pointer is dangerous
 * - why every malloc() should have a matching free()
 *
 * Embedded relevance:
 * Memory leaks are critical in embedded systems because:
 * - RAM is limited
 * - firmware often runs for long periods
 * - leaked memory is not recovered until reset
 * - repeated leaks can eventually crash the system
 *
 * NOTE:
 * The Extra Notes section contains detailed
 * memory diagrams and explanations of all
 * operations shown in this example.
 */

#include <stdio.h>
#include <stdlib.h>

void memory_leak_example(void)
{
    int *data = (int *)malloc(5 * sizeof(int));

    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        data[i] = (i + 1) * 10;
    }

    printf("Allocated data:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");

    /*
     * Memory leak:
     *
     * The allocated memory is not released with free().
     * When this function returns, the local pointer "data" is destroyed.
     *
     * After that, the allocated heap memory still exists,
     * but there is no pointer left to access or free it.
     */
}

void correct_memory_handling(void)
{
    int *data = (int *)malloc(5 * sizeof(int));

    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        data[i] = (i + 1) * 100;
    }

    printf("Correctly allocated data:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");

    free(data);
    data = NULL;
}

int main(void)
{
    memory_leak_example();

    correct_memory_handling();

    return 0;
}

/*
 * Extra Notes
 *
 * A memory leak happens when allocated heap memory is no longer reachable.
 *
 * Example:
 *
 * int *ptr = malloc(sizeof(int));
 * ptr = NULL;
 *
 * The address returned by malloc() is lost.
 * The memory is still allocated, but can no longer be freed.
 *
 *
 * Another common memory leak:
 *
 * void function(void)
 * {
 *    int *ptr = malloc(sizeof(int));
 * }
 *
 * What happens?
 *
 * 1. ptr is a local variable stored on the stack.
 *
 * 2. malloc() allocates memory on the heap and returns its address.
 *
 *    Stack                    Heap
 *    -----                    ----
 *    ptr  ------------------> allocated memory
 *
 * 3. When the function returns, the stack frame is destroyed.
 *
 *    ptr no longer exists.
 *    ptr no longer exists.
 *
 * 4. The heap memory still exists, but there is no pointer left
 *    that stores its address.
 *
 * 5. Because the address is lost, the memory can no longer be
 *    accessed or released with free().
 *
 * Result:
 * Memory Leak
 */
