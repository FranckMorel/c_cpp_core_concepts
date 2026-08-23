#include <stddef.h>
#include <stdio.h>

#define BUFFER_SIZE 7

/*
 * Topic: Circular Buffer
 *
 * Fixed-size FIFO buffer implemented using an array.
 *
 * head        -> next position to write to
 * tail        -> next position to read to
 * bufferCount -> number of stored elements
 *
 * Index:   0    1    2    3    4
        +----+----+----+----+----+
        | 10 | 20 | 30 |    |    |
        +----+----+----+----+----+
          ↑              ↑
        tail            head
 */

int Buffer[BUFFER_SIZE];

size_t head = 0;
size_t tail = 0;
size_t bufferCount = 0;


/* Function prototypes */
int isEmpty(void);
int isFull(void);
int bufferWrite(int data);
int bufferRead(int *data);


/*
 * Write a new element into the buffer.
 *
 * Returns:
 * 1 -> success
 * 0 -> buffer full
 */
int bufferWrite(int data)
{
    if (isFull())
    {
        return 0;
    }

    Buffer[head] = data;

    head++;

    /* Wrap around to the beginning */
    if (head >= BUFFER_SIZE)
    {
        head = 0;
    }

    bufferCount++;

    return 1;
}


/*
 * Read the oldest element from the buffer.
 *
 * Returns:
 * 1 -> success
 * 0 -> buffer empty
 */
int bufferRead(int *data)
{
    if (isEmpty())
    {
        return 0;
    }

    *data = Buffer[tail];

    tail++;

    /* Wrap around to the beginning */
    if (tail >= BUFFER_SIZE)
    {
        tail = 0;
    }

    bufferCount--;

    return 1;
}


/*
 * Check whether the buffer is empty.
 */
int isEmpty(void)
{
    return bufferCount == 0;
}


/*
 * Check whether the buffer is full.
 */
int isFull(void)
{
    return bufferCount == BUFFER_SIZE;
}


int main(void)
{
    int data;

    /*************************************************
     * Example 1:
     * Write initial values
     *************************************************/

    printf("Initial write:\n");

    for (int i = 0; i < 5; i++)
    {
        if (bufferWrite(i * 5))
        {
            printf("Written: %d\n", i * 5);
        }
        else
        {
            printf("Buffer is full\n");
        }
    }

    printf("\n");


    /*************************************************
     * Example 2:
     * Read three values
     *
     * This moves tail forward and creates
     * free space at the beginning of the array.
     *************************************************/

    printf("Reading three values:\n");

    for (int i = 0; i < 3; i++)
    {
        if (bufferRead(&data))
        {
            printf("Read: %d\n", data);
        }
        else
        {
            printf("Buffer is empty\n");
        }
    }

    printf("\n");


    /*************************************************
     * Example 3:
     * Write additional values
     *
     * head eventually reaches the end of the array
     * and wraps around to index 0.
     *************************************************/

    printf("Writing additional values:\n");

    for (int i = 0; i < 5; i++)
    {
        if (bufferWrite(i * 5))
        {
            printf("Written: %d\n", i * 5);
        }
        else
        {
            printf("Buffer is full\n");
        }
    }

    printf("\n");


    /*************************************************
     * Example 4:
     * Read all remaining values
     *
     * Expected FIFO order:
     *
     * 15
     * 20
     * 0
     * 5
     * 10
     * 15
     * 20
     *************************************************/

    printf("Reading remaining values:\n");

    while (bufferRead(&data))
    {
        printf("Read: %d\n", data);
    }

    printf("\nBuffer is empty\n");

    return 0;
}
