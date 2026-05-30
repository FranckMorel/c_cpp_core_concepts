/*
 * Topic: Heap Fragmentation
 *
 * This example demonstrates:
 * - how heap fragmentation occurs
 * - why repeated allocation and deallocation can be problematic
 * - why many embedded systems avoid dynamic allocation
 *
 * Embedded relevance:
 * Heap fragmentation can eventually prevent large allocations
 * even when enough total free memory still exists.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *block1 = (int *)malloc(100);
    int *block2 = (int *)malloc(100);
    int *block3 = (int *)malloc(100);

    if (block1 == NULL || block2 == NULL || block3 == NULL)
    {
        printf("Allocation failed\n");

        free(block1);
        free(block2);
        free(block3);

        return 1;
    }

    printf("Initial allocations:\n");
    printf("block1 = %p\n", (void *)block1);
    printf("block2 = %p\n", (void *)block2);
    printf("block3 = %p\n", (void *)block3);

    /*
     * Free the middle block.
     */

    free(block2);
    block2 = NULL;

    printf("\nMiddle block released.\n");

    /*
     * Heap now looks conceptually like:
     *
     * [USED][FREE][USED]
     */

    int *block4 = (int *)malloc(80);

    if (block4 != NULL)
    {
        printf("\nNew allocation:\n");
        printf("block4 = %p\n", (void *)block4);
    }

    /*
     * Depending on the allocator,
     * block4 may reuse the free region.
     */

    free(block1);
    free(block3);
    free(block4);

    block1 = NULL;
    block3 = NULL;
    block4 = NULL;

    return 0;
}

/*
 * Extra Notes
 *
 * Heap Fragmentation:
 *
 * Fragmentation occurs when free memory becomes split into
 * many small blocks separated by allocated blocks.
 *
 *
 * Example:
 *
 * Before:
 *
 * [FREE FREE FREE FREE FREE FREE]
 *
 *
 * After several allocations:
 *
 * [USED][USED][USED][USED]
 *
 *
 * After freeing some blocks:
 *
 * [USED][FREE][USED][FREE]
 *
 *
 * Problem:
 *
 * Total free memory may be large enough,
 * but it is no longer contiguous.
 *
 *
 * Example:
 *
 * [FREE 20B][USED][FREE 20B]
 *
 * Total free memory = 40B
 *
 * Request:
 *
 * malloc(30);
 *
 * May fail because there is no single contiguous
 * 30-byte region available.
 *
 *
 * Why Embedded Engineers Care:
 *
 * Embedded systems often run for:
 *
 * - hours
 * - days
 * - months
 * - years
 *
 * Repeated malloc/free operations can fragment the heap.
 *
 * For this reason many embedded systems:
 *
 * - avoid dynamic allocation completely
 * - allocate memory once at startup
 * - use static buffers
 * - use memory pools
 *
 *
 * Typical Embedded Recommendation:
 *
 * Allocate once.
 * Reuse memory.
 * Avoid frequent malloc/free cycles.
 */
