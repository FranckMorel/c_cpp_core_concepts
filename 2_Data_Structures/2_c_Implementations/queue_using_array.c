#include <stdio.h>

#define MAX_SIZE 10

/*
 * Topic: Queue using Array
 *
 * A Queue is a linear data structure that follows:
 *
 * FIFO -> First In First Out
 *
 * front points to the first element of the queue.
 * rear points to the last element of the queue.
 *
 * An empty queue is represented by:
 * front = -1
 * rear  = -1
 */

int A[MAX_SIZE];
int front = -1;
int rear = -1;


/*
 * Checks whether the queue is empty.
 *
 * Return:
 * 1 if the queue is empty
 * 0 otherwise
 */
int isEmpty(void)
{
    return front == -1 && rear == -1;
}


/*
 * Checks whether the array has reached its last position.
 *
 * Important:
 * This is a linear queue. Free positions before front cannot be reused
 * until the queue becomes completely empty.
 *
 * Return:
 * 1 if no more elements can be inserted
 * 0 otherwise
 */
int isFull(void)
{
    return rear == MAX_SIZE - 1;
}


/*
 * Inserts a new value at the rear of the queue.
 *
 * Parameter:
 * value -> value to be inserted
 *
 * Return:
 * 1 if the value was inserted successfully
 * 0 if the queue is full
 */
int Enqueue(int value)
{
    if (isFull())
    {
        printf("Queue overflow!\n");
        return 0;
    }

    /*
     * When inserting the first element, both front and rear
     * must point to index 0.
     */
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }

    A[rear] = value;

    return 1;
}


/*
 * Removes the value at the front of the queue.
 *
 * The removed value is written to the address passed through value.
 *
 * Example:
 *
 * int removedValue;
 * Dequeue(&removedValue);
 *
 * Parameter:
 * value -> pointer to the variable in which the removed value is stored
 *
 * Return:
 * 1 if an element was removed successfully
 * 0 if the queue is empty or the pointer is invalid
 */
int Dequeue(int *value)
{
    if (value == NULL)
    {
        printf("Invalid output pointer!\n");
        return 0;
    }

    if (isEmpty())
    {
        printf("No elements in the queue!\n");
        return 0;
    }

    /*
     * Store the first queue element in the caller's variable.
     */
    *value = A[front];

    /*
     * If front and rear are equal, the last remaining element
     * has just been removed. Reset the queue to its empty state.
     */
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        /*
         * Move front to the next element.
         * The array elements themselves are not shifted.
         */
        front++;
    }

    return 1;
}


/*
 * Returns the first element without removing it.
 *
 * Return:
 * Value at the front of the queue
 *
 * Note:
 * Returning 0 on failure is ambiguous because 0 could also be a valid
 * queue value. A pointer-based version would handle this more cleanly.
 */
int peek(void)
{
    if (isEmpty())
    {
        printf("No elements in the queue!\n");
        return 0;
    }

    return A[front];
}


/*
 * Prints all active elements of the queue.
 *
 * Only the range from front to rear belongs to the queue.
 */
void printQueue(void)
{
    if (isEmpty())
    {
        printf("No elements in the queue!\n");
        return;
    }

    printf("Elements of the queue: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nFront: %d, Rear: %d\n", A[front], A[rear]);
}


/*
 * Prints the first 'size' elements of any integer array.
 *
 * This function does not use the queue indices front and rear.
 * It is therefore suitable for printing the separately stored
 * dequeued values.
 */
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}


int main(void)
{
    int dequeuedValues[MAX_SIZE];
    int count = 0;

    /*
     * Fill the queue with multiples of 3:
     * 3, 6, 9, ..., 30
     *
     * The queue state is checked before Enqueue() is called.
     * This prevents an additional failed Enqueue() call after
     * the queue has already become full.
     */
    while (!isFull())
    {
        Enqueue((count + 1) * 3);
        count++;
    }

    printQueue();

    /*
     * Reuse count as the number of successfully removed elements.
     */
    count = 0;

    /*
     * Remove all elements and store them in dequeuedValues.
     *
     * The queue state is checked before Dequeue() is called.
     * This prevents an additional failed Dequeue() call after
     * the queue has already become empty.
     *
     * count < MAX_SIZE also prevents writing beyond the end
     * of dequeuedValues.
     */
    while (!isEmpty() && count < MAX_SIZE)
    {
        Dequeue(&dequeuedValues[count]);
        count++;
    }

    printf("\nDequeued elements: ");
    printArray(dequeuedValues, count);

    return 0;
}
