/*
 * Topic: Stack using Array
 *
 * A Stack is a linear data structure that follows:
 *
 * LIFO -> Last In First Out
 *
 * Only the top element can be accessed.
 *
 * Operations:
 * - push()
 * - pop()
 * - peek()
 * - isEmpty()
 * - printStack()
 *
 * All operations execute in O(1).
 *
 * Applications:
 * - Function Calls
 * - Recursion
 * - Undo / Redo Systems
 * - Expression Evaluation
 * - Balanced Parentheses
 *
 * NOTE:
 * See Extra Notes at the bottom for detailled explanation
 * for each function using memory diagrams
 */

#include <stdio.h>

#define MAX_SIZE 101

int stack[MAX_SIZE];
int top = -1;

/*
 * Insert a new element on top of the stack.
 */
int push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: Stack Overflow\n");
        return 0;
    }

    top++;
    stack[top] = value;

    return 1;
}

/*
 * Remove the top element.
 *
 * The removed value is returned
 * through the pointer parameter.
 */
int pop(int *value)
{
    if (top == -1)
    {
        return 0;
    }

    *value = stack[top];
    top--;

    return 1;
}

/*
 * Read the top element
 * without removing it.
 */
int peek(int *value)
{
    if (top == -1)
    {
        return 0;
    }

    *value = stack[top];

    return 1;
}

/*
 * Check whether the stack is empty.
 */
int isEmpty(void)
{
    return (top == -1);
}

/*
 * Print all stack elements.
 */
void printStack(void)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main(void)
{
    push(5);
    printStack();

    push(3);
    printStack();

    push(12);
    printStack();

    int value;

    if (pop(&value))
    {
        printf("Popped: %d\n", value);
    }

    printStack();

    if (peek(&value))
    {
        printf("Top element: %d\n", value);
    }

    return 0;
}

/*
===============================================================================
EXTRA NOTES
===============================================================================

1. Stack Concept
----------------

A stack follows:

LIFO

Last In First Out


Example:

push(10)
push(20)
push(30)

Stack:

30 <-- Top
20
10

pop()

returns: 30

===============================================================================

2. Array Representation
-----------------------

Array:

+----+----+----+----+----+
| 10 | 20 | 30 |    |    |
+----+----+----+----+----+
             ^
            top


top stores the index of the last inserted element.

===============================================================================

3. Empty Stack
--------------

Initially:

top = -1

Meaning:

No valid element exists.


Array:

+----+----+----+----+
|    |    |    |    |
+----+----+----+----+

top = -1


===============================================================================

4. Push Operation
-----------------

Before:

top = 1

+----+----+----+----+
| 10 | 20 |    |    |
+----+----+----+----+
        ^
       top


push(30)

Step 1:

top++

top = 2


Step 2:

stack[top] = 30


Result:

+----+----+----+----+
| 10 | 20 | 30 |    |
+----+----+----+----+
             ^
            top


===============================================================================

5. Stack Overflow
-----------------

Array size: 101

Maximum valid index: 100

If:

top == MAX_SIZE - 1

then:

No additional element can be inserted.


This condition is called:

Stack Overflow


===============================================================================

6. Pop Operation
----------------

Before:

+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
             ^
            top


pop()

returns: 30

Step:

top--


Result:

+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
        ^
       top


30 still exists in memory,
but it is no longer part of the stack.


===============================================================================

7. Peek Operation
-----------------

peek()

returns the top element
without removing it.


Before:

+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
             ^
            top


peek()

returns: 30

Stack remains unchanged.

===============================================================================

8. isEmpty()
------------

Stack is empty when:

top == -1


Implementation:

return (top == -1);


Returns:

1 -> true
0 -> false


===============================================================================

9. Time Complexity
------------------

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


===============================================================================

10. Array Stack vs Linked List Stack
------------------------------------

Array Stack

Advantages:
- Fast
- Cache Friendly
- Simple

Disadvantages:
- Fixed Size
- Possible Overflow


===============================================================================

11. Applications
----------------

Function Calls

main()
  |
  +--> foo()
          |
          +--> bar()

Return addresses are stored on a stack.


Undo / Redo

User Actions:

Write A
Write B
Write C

Stack:

C
B
A

Undo removes C first.


Balanced Parentheses

Example:

((()))

Opening brackets are pushed.

Closing brackets pop them.

If stack is empty too early:

Expression is invalid.


===============================================================================
*/
