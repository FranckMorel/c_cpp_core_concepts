#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        return;
    }

   newNode->data = value;

   newNode->next = top;
   top = newNode;
}

int pop(int* value){
    if(top == NULL)
    {
        return 0;
    }
    struct Node *temp = top;

    *value = temp->data;
    top = temp->next;
    free(temp);
    return 1;
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}


int peek(int* value)
{
    if(top == NULL)
    {
        return 0;
    }

    *value = top->data;
    return 1;
}

void freeStack(){
    struct Node *currentNode = top;

    while (currentNode != NULL)
    {
        struct Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    top = NULL;
}


void printStackList(){
    struct Node *currentNode = top;
    if (top == NULL)
    {

        return;
    }
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(){
    push(3);printStackList();
    push(12);printStackList();
    push(5);printStackList();
    push(10);printStackList();

    int poppedValue;

    for (int i = 0; i < 5; i++)
    {
        if (pop(&poppedValue))
        {
            printf("Value popped: %d\n", poppedValue);
            printStackList();
        }else
        {
            printf("Error: Stack is empty");
        }
    }

}
