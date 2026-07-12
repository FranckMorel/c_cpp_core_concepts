#include <stdio.h>
#include <stdlib.h>

/*
 * Queue Implementation using a Singly Linked List
 *
 * FIFO Principle:
 * First In, First Out
 *
 * Unlike the array implementation, this queue
 * grows dynamically and does not require a
 * predefined maximum size.
 */

struct Node
{
    int data;
    struct Node *next;
};

/*
 * front
 * Points to the first queue element.
 *
 * rear
 * Points to the last queue element.
 */
struct Node *front = NULL;
struct Node *rear = NULL;


/**************************************************************************************************
 * Insert a new element at the rear of the queue.
 *
 * Algorithm:
 * 1. Allocate memory for a new node.
 * 2. Store the value.
 * 3. Append the node at the end.
 * 4. Update rear.
 *
 * Time Complexity:
 * O(1)
 **************************************************************************************************/
int Enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(*newNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    newNode->data = value;
    newNode->next = NULL;

    /*
     * Empty Queue
     */
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    return 1;
}


/*******************************************************************************
 * Remove the first queue element.
 *
 * The removed value is written into the variable
 * provided by the caller.
 *
 * Time Complexity:
 * O(1)
 ******************************************************************************/
int Dequeue(int *dequeuedValue)
{
    if (front == NULL)
    {
        printf("No elements in the queue.\n");
        return 0;
    }

    *dequeuedValue = front->data;

    struct Node *temp = front;

    /*
     * Last remaining element
     */
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);

    return 1;
}


/********************************************************************************
 * Return the first queue element without removing it.
 *
 * Time Complexity:
 * O(1)
 ********************************************************************************/
int peek(void)
{
    if (front == NULL)
    {
        printf("No elements in the queue.\n");
        return 0;
    }

    return front->data;
}


/**********************************************************************************
 * Check whether the queue is empty.
 *********************************************************************************/
int isEmpty(void)
{
    return front == NULL;
}


/**********************************************************************************
 * Print all queue elements.
 *
 * Time Complexity:
 * O(n)
 *********************************************************************************/
void printQueue(void)
{
    struct Node *currentNode = front;

    if (currentNode == NULL)
    {
        printf("No elements in the queue.\n");
        return;
    }

    printf("Elements in the queue: ");

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");

    printf("Front: %d\n", front->data);
    printf("Rear : %d\n", rear->data);
}


/**********************************************************************************
 * Print an integer array.
 *********************************************************************************/
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}


/**********************************************************************************
 * Free all remaining queue nodes.
 *
 * Useful before program termination.
 *********************************************************************************/
void clearQueue(void)
{
    int value;

    while (Dequeue(&value))
        ;
}


/*********************************************************************************
 * Main
 ********************************************************************************/
int main(void)
{
    int dequeuedValues[10];
    int count = 0;

    /*************************************************
     * Example 1:
     * Insert values into the queue
     *************************************************/

    for (int i = 1; i <= 10; i++)
    {
        Enqueue(i * 5);
    }

    printQueue();

    printf("\n");

    /*************************************************
     * Example 2:
     * Read the front element without removing it
     *************************************************/

    printf("Front Element: %d\n\n", peek());

    /*************************************************
     * Example 3:
     * Remove all queue elements
     *
     * Store every removed value to verify
     * FIFO behavior.
     *************************************************/

    while (!isEmpty())
    {
        Dequeue(&dequeuedValues[count]);
        count++;
    }

    printf("Dequeued Elements: ");
    printArray(dequeuedValues, count);

    /*
     * Queue is already empty.
     * Calling clearQueue() is still safe.
     */
    clearQueue();

    return 0;
}
