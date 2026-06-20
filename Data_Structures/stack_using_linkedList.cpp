/*
 * Topic: Stack using Linked List
 *
 * This example demonstrates:
 * - push operation
 * - pop operation
 * - peek operation
 * - checking whether the stack is empty
 * - stack traversal
 * - dynamic memory management
 *
 * NOTE:
 * See Extra Notes at the bottom for detailed explanation
 * and memory diagrams.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/*
 * top always points to the
 * first node of the stack.
 */
struct Node *top = NULL;

/*
 * Insert a new element
 * on top of the stack.
 */
void push(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(*newNode));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;

    /*
     * Link new node to old top.
     */
    newNode->next = top;

    /*
     * Move top to new node.
     */
    top = newNode;
}

/*
 * Remove the top element.
 *
 * Returns:
 * 1 -> success
 * 0 -> stack empty
 *
 * The removed value is stored
 * inside *value.
 */
int pop(int *value)
{
    if (top == NULL)
    {
        return 0;
    }

    struct Node *temp = top;

    *value = temp->data;

    top = temp->next;

    free(temp);

    return 1;
}

/*
 * Read the top element
 * without removing it.
 */
int peek(int *value)
{
    if (top == NULL)
    {
        return 0;
    }

    *value = top->data;

    return 1;
}

/*
 * Check if stack is empty.
 */
int isEmpty(void)
{
    return (top == NULL);
}

/*
 * Print complete stack.
 */
void printStack(void)
{
    struct Node *currentNode = top;

    if (currentNode == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

/*
 * Free complete stack.
 */
void freeStack(void)
{
    struct Node *currentNode = top;

    while (currentNode != NULL)
    {
        struct Node *nextNode = currentNode->next;

        free(currentNode);

        currentNode = nextNode;
    }

    top = NULL;
}

int main(void)
{
    push(3);
    printStack();

    push(12);
    printStack();

    push(5);
    printStack();

    push(10);
    printStack();

    int poppedValue;

    for (int i = 0; i < 5; i++)
    {
        if (pop(&poppedValue))
        {
            printf("Value popped: %d\n", poppedValue);
            printStack();
        }
        else
        {
            printf("Error: Stack is empty\n");
        }
    }

    freeStack();

    return 0;
}

/*
===============================================================================
EXTRA NOTES
===============================================================================

1. Why Linked List?
-------------------

Unlike an array stack:

- size is dynamic
- no fixed capacity
- grows as long as memory is available


Array Stack:

[10][20][30][40]

Fixed size


Linked List Stack:

10 -> 20 -> 30 -> NULL

Dynamic size


===============================================================================

2. The top Pointer
------------------

top always points to the first node.

Example:

top
 |
 v

[30] -> [20] -> [10] -> NULL


The top element is always:

top->data

===============================================================================

3. Empty Stack
--------------

Initially:

top = NULL


Meaning:

No element exists.


Stack:

top
 |
NULL


===============================================================================

4. Push Operation
-----------------

Before:

top
 |
 v

[20] -> [10] -> NULL


push(30)

Step 1:

Allocate memory.

newNode
 |
 v

[30]


Step 2:

Link new node to old top.

newNode->next = top


[30] -----> [20] -> [10]


Step 3:

Move top.

top = newNode


Result:

top
 |
 v

[30] -> [20] -> [10] -> NULL


Complexity:

O(1)


===============================================================================

5. Pop Operation
----------------

Before:

top
 |
 v

[30] -> [20] -> [10] -> NULL


Step 1:

Store current top.

temp = top


Step 2:

Read value.

value = temp->data


Step 3:

Move top.

top = temp->next


Now:

top
 |
 v

[20] -> [10] -> NULL


Step 4:

Free old node.

free(temp)


Complexity:

O(1)


===============================================================================

6. Peek Operation
-----------------

peek()

returns the value of the top node
without removing it.


Before:

top
 |
 v

[30] -> [20] -> [10]


peek()

returns:

30


Stack remains unchanged.


Complexity:

O(1)


===============================================================================

7. isEmpty()
------------

The stack is empty when:

top == NULL


Implementation:

return (top == NULL);


Returns:

1 -> true
0 -> false


Complexity:

O(1)


===============================================================================

8. Print Stack
---------------

Traversal starts at top.

Example:

top
 |
 v

[30] -> [20] -> [10] -> NULL


Output:

30 20 10


Complexity:

O(n)


===============================================================================

9. Free Stack
--------------

Every dynamically allocated node
must eventually be freed.

Before:

top
 |
 v

[30] -> [20] -> [10] -> NULL


Iteration 1:

nextNode = 20

free(30)

currentNode = 20


Iteration 2:

nextNode = 10

free(20)

currentNode = 10


Iteration 3:

nextNode = NULL

free(10)

currentNode = NULL


Finally:

top = NULL


===============================================================================

10. Time Complexity
-------------------

push()
O(1)

pop()
O(1)

peek()
O(1)

isEmpty()
O(1)

printStack()
O(n)

freeStack()
O(n)


===============================================================================

11. Array Stack vs Linked List Stack
------------------------------------

Linked List Stack

Advantages:
- Dynamic size
- No fixed capacity

Disadvantages:
- Requires malloc/free
- Additional memory for next pointer

===============================================================================
*/


/*Draft
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
*/
