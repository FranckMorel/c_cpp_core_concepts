/*
 * Topic: Stack vs Heap
 *
 * This example demonstrates:
 * - automatic memory allocation on the stack
 * - dynamic memory allocation on the heap
 * - lifetime differences between stack and heap memory
 * - why heap memory must be released manually
 *
 * Embedded relevance:
 * Understanding stack and heap is important for:
 * - avoiding stack overflow
 * - controlling RAM usage
 * - avoiding memory leaks
 * - designing predictable firmware
 * - deciding between static and dynamic allocation
 */

#include <stdio.h>
#include <stdlib.h>

void stack_example(void)
{
    /*
     * Local variables are usually stored on the stack.
     * Their lifetime ends when the function returns.
     */

    int localValue = 10;

    printf("Stack value: %d\n", localValue);
    printf("Stack address: %p\n\n", (void *)&localValue);
}

void heap_example(void)
{
    /*
     * malloc() allocates memory on the heap.
     * The memory remains allocated until free() is called.
     */

    int *heapValue = (int *)malloc(sizeof(int));

    if (heapValue == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    *heapValue = 20;

    printf("Heap value: %d\n", *heapValue);
    printf("Heap address: %p\n\n", (void *)heapValue);

    /*
     * Important:
     * Every successful malloc() should have a matching free().
     */

    free(heapValue);

    /*
     * Important:
     *
     * After free(), heapValue still contains the old address,
     * but the memory is no longer valid.
     *
     * Accessing *heapValue after free() would be undefined behavior.
     */

    heapValue = NULL;
}

int main(void)
{
    stack_example();
    heap_example();

    /*
     * Summary:
     *
     * Stack:
     * - automatic allocation
     * - automatic cleanup
     * - fast
     * - limited size
     *
     * Heap:
     * - dynamic allocation
     * - manual cleanup with free()
     * - flexible size
     * - risk of leaks and fragmentation
     */

    return 0;
}
