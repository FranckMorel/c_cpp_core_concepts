/*
 * Topic: Dangling Pointer
 *
 * This example demonstrates:
 * - what a dangling pointer is
 * - why free() does not reset a pointer
 * - why returning the address of a local variable is unsafe
 * - how to avoid dangling pointers
 *
 * Embedded relevance:
 * Dangling pointers can cause random crashes, corrupted data,
 * hard-to-debug firmware faults and unpredictable system behavior.
 *
 * NOTE:
 * The Extra Notes section contains detailed explanations
 * of all operations shown in this example.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Dangerous example:
 *
 * Returning the address of a local stack variable.
 */
int* invalid_return_address(void)
{
    int value = 10;

    /*
     * value is stored on the stack.
     * When this function returns, value no longer exists.
     *
     * Returning &value creates a dangling pointer.
     */
    return &value;
}

/*
 * Safe alternative:
 *
 * Return the value itself.
 */
int return_value(void)
{
    int value = 10;
    return value;
}

/*
 * Safe alternative for multiple values:
 *
 * Use output parameters.
 */
void get_values(int *a, int *b)
{
    *a = 10;
    *b = 20;
}

int main(void)
{
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 42;

    printf("Value before free(): %d\n", *ptr);
    printf("Pointer before free(): %p\n\n", (void *)ptr);

    /*
     * free() releases the heap memory.
     *
     * Important:
     * free(ptr) does NOT change ptr itself.
     * ptr still contains the old address.
     */
    free(ptr);

    printf("Pointer after free(): %p\n", (void *)ptr);

    /*
     * ptr is now a dangling pointer:
     *
     * - the pointer variable still exists
     * - but the memory it points to is no longer valid
     *
     * The following would be undefined behavior:
     *
     * printf("%d\n", *ptr);
     */

    /*
     * Good practice:
     *
     * Set pointer to NULL after free().
     * This makes it clear that it no longer points to valid memory.
     */
    ptr = NULL;

    /*
     * Safe value return.
     */
    int value = return_value();
    printf("Returned value: %d\n", value);

    /*
     * Unsafe pointer return.
     */
    int *invalid = invalid_return_address();
    printf("%p\n", (void *)invalid);

    /*
     * Safe multiple-value return using output parameters.
     */
    int x = 0;
    int y = 0;

    get_values(&x, &y);

    printf("Output values: x = %d, y = %d\n", x, y);

    return 0;
}

/*
 * Extra Notes
 *
 * Dangling Pointer:
 *
 * A dangling pointer is a pointer that still stores an address,
 * but the memory at that address is no longer valid.
 *
 *
 * Case 1: Access after free()
 *
 * int *ptr = malloc(sizeof(int));
 *
 * *ptr = 42;
 *
 * free(ptr);
 *
 * ptr still contains the old address, but the heap memory
 * has already been released.
 *
 * Accessing *ptr after free() is undefined behavior.
 *
 *
 * Case 2: Returning address of a local variable
 *
 * int* function(void)
 * {
 *     int value = 10;
 *     return &value;
 * }
 *
 * What happens?
 *
 * 1. value is a local variable stored on the stack.
 *
 * 2. &value returns its address while the function is still running.
 *
 * 3. When the function returns, its stack frame is destroyed.
 *
 * 4. value no longer exists.
 *
 * 5. The returned pointer still contains the old address,
 *    but that address no longer refers to a valid object.
 *
 * Result:
 * Dangling pointer.
 *
 *
 * Important distinction:
 *
 * Saving an address does not mean the object behind that address
 * is still alive.
 *
 *
 * Safe alternatives:
 *
 * 1. Return the value directly:
 *
 * int function(void)
 * {
 *     int value = 10;
 *     return value;
 * }
 *
 *
 * 2. Return multiple values using a struct or output parameters:
 *
 * void get_values(int *a, int *b)
 * {
 *     *a = 10;
 *     *b = 20;
 * }
 *
 *
 * 3. Use heap memory only when the data must remain valid
 *    after the function returns:
 *
 * int* function(void)
 * {
 *     int *ptr = malloc(sizeof(int));
 *     *ptr = 10;
 *     return ptr;
 * }
 *
 * In this case, the caller becomes responsible for calling free().
 *
 *
 * Memory Leak vs Dangling Pointer:
 *
 * Memory Leak:
 * -> memory still exists
 * -> pointer/address is lost
 *
 * Dangling Pointer:
 * -> pointer still exists
 * -> memory/object is no longer valid
 */
