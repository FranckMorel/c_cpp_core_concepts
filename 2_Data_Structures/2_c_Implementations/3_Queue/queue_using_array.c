#include <stdio.h>

#define MAX_SIZE 10

int A[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (rear == (sizeof(A) / sizeof(A[0])) - 1)
        return 1;
    else
        return 0;
}

int Enqueue(int value)
{
    if (isFull())
    {
        printf("QUEUE Overflow");
        return 0;
    }

   if (front == -1)
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

int Dequeue(int* value)
{
    if (isEmpty())
    {
        printf("No Elements in the QUEUE!");
        return 0;
    }

    *value = A[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return 1;
}

int peek()
{
    if (isEmpty())
    {
        printf("No Elements in the QUEUE!");
        return 0;
    }

    return A[front];
}

void printQueue(int* A)
{
    if (isEmpty())
    {
        printf("No Elements in the QUEUE!");
        return;
    }

    //printf("Elements of the QUEUE: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
    printf("Front: %d , Rear: %d", A[front], A[rear]);
}


int main()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Enqueue(((i+1) * 3));
    }
    printf("Eements of the QUEUE: ");
    printQueue(A);

    int dequeuedValues[10];
    int count = 0;
    while(Dequeue(&dequeuedValues[count]))
    {
        count++;
    }

    printf("\nDequeued Elements: ");
    printQueue(dequeuedValues);
}
