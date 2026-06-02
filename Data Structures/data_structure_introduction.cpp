/*
 * Topic: Introduction to Data Structures
 *
 * This example introduces:
 * - what a data structure is
 * - why data structures exist
 * - common data structure operations
 * - Abstract Data Types (ADTs)
 * - implementation vs abstraction
 * - linear vs non-linear data structures
 * - static vs dynamic data structures
 * - time complexity basics
 * - data structures in embedded systems
 *
 */

#include <stdio.h>

int main(void)
{
    printf("Introduction to Data Structures\n");

    return 0;
}

/*
===============================================================================
WHAT IS A DATA STRUCTURE?
===============================================================================

A data structure is a method of organizing and storing data in memory.

The goal is to perform operations efficiently.

Examples:

- Array
- Linked List
- Stack
- Queue
- Tree
- Hash Table
- Graph

Without data structures, programs would simply have a large collection
of variables with no efficient way to organize or access them.

===============================================================================
WHY DO WE NEED DATA STRUCTURES?
===============================================================================

Imagine storing 10 sensor values:

sensor1
sensor2
sensor3
...
sensor10

This quickly becomes difficult to manage.

Instead:

int sensors[10];

The data is now organized.

As programs become larger, more sophisticated data structures become
necessary.

===============================================================================
DATA VS DATA STRUCTURE
===============================================================================

Data:

10
20
30

These are simply values.

Data Structure:

[10][20][30]

Now the values have organization and relationships.

A data structure defines:

- how data is stored
- how data is accessed
- how data is modified

===============================================================================
COMMON OPERATIONS
===============================================================================

Every data structure supports operations.

Access
-------
Read a value.

Example:

array[3]

Insert
-------
Add a new element.

Example:

10 20 30

Insert 40

10 20 30 40

Delete
-------
Remove an element.

Search
-------
Find an element.

Example:

Find value 20.

Traversal
---------
Visit every element.

Example:

for loop through an array.

===============================================================================
ABSTRACT DATA TYPE (ADT)
===============================================================================

One of the most important concepts.

An ADT describes:

- what a structure can do

It does NOT describe:

- how it is implemented

Example:

Stack ADT

Operations:

push()
pop()
top()

The ADT does not care whether the stack is implemented using:

- Array
- Linked List
- Dynamic Array

Only the behavior matters.

===============================================================================
EXAMPLE: STACK ADT
===============================================================================

Imagine a stack of books.

Only the top book can be removed.

Allowed operations:

push()
add new item

pop()
remove top item

top()
inspect top item

This behavior defines the ADT.

===============================================================================
IMPLEMENTATION
===============================================================================

The actual code used to realize the ADT.

Example:

Stack ADT

Implementation #1

Array

[10][20][30]

Implementation #2

Linked List

10 -> 20 -> 30

Both implement the same ADT.

===============================================================================
LINEAR VS NON-LINEAR DATA STRUCTURES
===============================================================================

Linear Data Structures

Elements follow one another.

Examples:

- Array
- Linked List
- Stack
- Queue

Example:

10 -> 20 -> 30 -> 40

Non-Linear Data Structures

Elements may branch.

Examples:

- Tree
- Graph

Example:

        A
       / \
      B   C
         / \
        D   E

===============================================================================
STATIC VS DYNAMIC DATA STRUCTURES
===============================================================================

Static

Size is fixed.

Example:

int array[100];

Memory is determined at compile time.

Advantages:

- simple
- predictable
- fast

Common in embedded systems.

Dynamic

Size can change during runtime.

Examples:

- Linked Lists
- Dynamic Arrays
- Trees

Memory is allocated during execution.

Advantages:

- flexible

Disadvantages:

- more complex
- possible memory leaks
- possible fragmentation

===============================================================================
TIME COMPLEXITY
===============================================================================

Not all data structures perform equally.

Example:

Array access

array[5]

Cost:

O(1)

Linked List access

Must traverse nodes.

Cost:

O(n)

Different structures optimize different operations.

===============================================================================
EMBEDDED SYSTEM PERSPECTIVE
===============================================================================

In embedded systems, memory is limited.

Important considerations:

- RAM usage
- Flash usage
- Execution time
- Deterministic behavior

Because of this:

Arrays are often preferred.

Linked Lists are useful when:

- size changes during runtime
- insertion/deletion is frequent

But dynamic allocation must be used carefully.

===============================================================================
KEY TERMS
===============================================================================

Data Structure
--------------
Organization of data in memory.

Abstract Data Type (ADT)
---
Defines behavior, not implementation.

Node
----
Basic element of a linked list or tree.

Traversal
---------
Visiting all elements.

Complexity
----------
Measure of algorithm cost.

O(1)
-----
Constant time.

O(n)
-----
Linear time.
===============================================================================
*/
