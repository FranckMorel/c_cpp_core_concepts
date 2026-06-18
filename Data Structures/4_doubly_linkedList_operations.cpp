/*
 * Topic: Doubly Linked List Operations
 *
 * This example demonstrates:
 * - list length calculation
 * - insert node at a specific position
 * - delete node by pointer
 * - search node by value
 * - reverse a doubly linked list
 * - forward traversal
 * - backward traversal
 * - safe dynamic memory handling
 *
 * NOTE:
 * See Extra Notes at the bottom for detailed explanation
 * for each function using memory diagrams.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

/*
 * Count the number of nodes in the list.
 *
 * This function does not modify the list.
 */
int listLength(struct Node *head)
{
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

/*
 * Insert a node at position pos.
 *
 * Valid insert positions:
 * 0 to length
 *
 * Example:
 * List length = 5
 * Valid positions = 0, 1, 2, 3, 4, 5
 */
int insertAt_nPosition(struct Node **head, int value, int pos)
{
    int length = listLength(*head);

    if (pos < 0 || pos > length)
    {
        printf("Invalid position\n");
        return 0;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(*newNode));

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    /*
     * Special case:
     * Insert at the beginning of the list.
     */
    if (pos == 0)
    {
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }

        *head = newNode;
        return 1;
    }

    /*
     * Traverse to the node before the target position.
     */
    struct Node *currentNode = *head;

    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
    }

    /*
     * Insert newNode between currentNode and currentNode->next.
     */
    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }

    currentNode->next = newNode;

    return 1;
}

/*
 * Search for a node by value.
 *
 * Returns:
 * - pointer to the node if found
 * - NULL if not found
 */
struct Node *findNode(struct Node *head, int value)
{
    struct Node *currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->data == value)
        {
            return currentNode;
        }

        currentNode = currentNode->next;
    }

    return NULL;
}

/*
 * Delete a node from the list.
 *
 * The node is passed directly as a pointer.
 *
 * This function handles:
 * - deleting the first node
 * - deleting the last node
 * - deleting a middle node
 */
void deleteNode(struct Node **head, struct Node *nodeToDelete)
{
    if (*head == NULL || nodeToDelete == NULL)
    {
        return;
    }

    /*
     * Case 1:
     * Node to delete is the first node.
     */
    if (nodeToDelete->prev == NULL)
    {
        *head = nodeToDelete->next;

        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }

        free(nodeToDelete);
        return;
    }

    /*
     * Case 2:
     * Node to delete is the last node.
     */
    if (nodeToDelete->next == NULL)
    {
        nodeToDelete->prev->next = NULL;
        free(nodeToDelete);
        return;
    }

    /*
     * Case 3:
     * Node to delete is in the middle.
     */
    nodeToDelete->next->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;

    free(nodeToDelete);
}

/*
 * Reverse the complete doubly linked list.
 *
 * In a doubly linked list, reversing means:
 * - next becomes prev
 * - prev becomes next
 */
void reverseList(struct Node **head)
{
    struct Node *currentNode = *head;
    struct Node *newHead = NULL;
    struct Node *temp = NULL;

    if (*head == NULL)
    {
        return;
    }

    while (currentNode != NULL)
    {
        temp = currentNode->prev;

        currentNode->prev = currentNode->next;
        currentNode->next = temp;

        newHead = currentNode;

        /*
         * After swapping next and prev,
         * the next node in the original list is now currentNode->prev.
         */
        currentNode = currentNode->prev;
    }

    *head = newHead;
}

/*
 * Print list from head to tail.
 */
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

/*
 * Print list from tail to head.
 */
void printReverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }

    struct Node *currentNode = head;

    /*
     * First go to the last node.
     */
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    /*
     * Then move backwards using prev.
     */
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    }

    printf("\n");
}

/*
 * Free the complete list.
 */
void freeList(struct Node **head)
{
    struct Node *currentNode = *head;

    while (currentNode != NULL)
    {
        struct Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;
}

int main(void)
{
    struct Node *head = NULL;
    int pos = 0;

    /*
     * Build list:
     * 0 5 10 15 20 25
     */
    for (int i = 0; i < 6; i++)
    {
        if (insertAt_nPosition(&head, i * 5, pos))
        {
            pos++;
        }
    }

    printf("Original list: ");
    printList(head);

    printf("Backward traversal: ");
    printReverse(head);

    reverseList(&head);

    printf("List after reverse: ");
    printList(head);

    struct Node *nodeToDelete = findNode(head, 15);
    deleteNode(&head, nodeToDelete);

    printf("List after delete: ");
    printList(head);

    if (insertAt_nPosition(&head, 99, 8))
    {
        printf("List after insert: ");
        printList(head);
    }

    freeList(&head);

    return 0;
}

/*
===============================================================================
EXTRA NOTES
===============================================================================

1. Node structure
-----------------

A doubly linked list node contains:

[ prev | data | next ]

prev:
- stores the address of the previous node

data:
- stores the value

next:
- stores the address of the next node


Example:

NULL <- [10] <-> [20] <-> [30] -> NULL


===============================================================================

2. Difference between singly and doubly linked list
---------------------------------------------------

Singly linked list:

[10 | next] -> [20 | next] -> [30 | NULL]


Doubly linked list:

NULL <- [10] <-> [20] <-> [30] -> NULL


A doubly linked list can move:

- forward using next
- backward using prev


===============================================================================

3. Head pointer
---------------

head stores the address of the first node.

head
 |
 v

NULL <- [10] <-> [20] <-> [30] -> NULL


If head is lost, the list cannot be accessed safely anymore.


===============================================================================

4. Why Node** head is used
--------------------------

Functions that may change the real head pointer need:

struct Node **head

Example functions:

insertAt_nPosition()
deleteNode()
reverseList()


Because these operations can change the first node of the list.


Example:

Before inserting 5 at position 0:

head
 |
 v

[10] <-> [20] -> NULL


After inserting 5:

head
 |
 v

[5] <-> [10] <-> [20] -> NULL


The actual head pointer changed.


===============================================================================

5. Insert at position 0
-----------------------

Before:

head
 |
 v

NULL <- [10] <-> [20] -> NULL


Insert 5 at position 0.

Step 1:

newNode
 |
 v

[5]


Step 2:

newNode->next = *head;

[5] -----> [10] <-> [20]


Step 3:

old head must point back to newNode:

(*head)->prev = newNode;


Result:

head
 |
 v

NULL <- [5] <-> [10] <-> [20] -> NULL


Important:

If the list is empty, *head is NULL.

Therefore this check is needed:

if (*head != NULL)
{
    (*head)->prev = newNode;
}


Without this check, the program would dereference NULL and crash.


===============================================================================

6. Insert in the middle
-----------------------

Example:

List:

Position:
0       1       2

10 <-> 20 <-> 30

Insert 99 at position 2.

Target result:

10 <-> 20 <-> 99 <-> 30


Step 1:
Traverse to pos - 1.

currentNode
    |
    v

  [20]


Step 2:
Connect newNode to the next node.

newNode->next = currentNode->next;

[99] -----> [30]


Step 3:
Connect newNode back to currentNode.

newNode->prev = currentNode;

[20] <----- [99]


Step 4:
If there is a node after newNode, update its prev pointer.

newNode->next->prev = newNode;

[99] <----- [30]


Step 5:
Connect currentNode forward to newNode.

currentNode->next = newNode;


Final:

10 <-> 20 <-> 99 <-> 30


===============================================================================

7. Insert at the end
--------------------

Example:

List:

10 <-> 20 <-> 30 -> NULL

Insert 99 at position 3.


currentNode points to node 30.

newNode->next = currentNode->next;

Since currentNode->next is NULL:

newNode->next = NULL;


newNode->prev = currentNode;

30 <----- 99


currentNode->next = newNode;


Final:

10 <-> 20 <-> 30 <-> 99 -> NULL


The condition:

if (newNode->next != NULL)

is important because at the end of the list there is no next node.


===============================================================================

8. Delete first node
--------------------

Example:

head
 |
 v

NULL <- [10] <-> [20] <-> [30] -> NULL


Delete node 10.

Step 1:

*head = nodeToDelete->next;


Now head points to 20:

head
 |
 v

[20] <-> [30]


Step 2:

Set new head prev to NULL:

(*head)->prev = NULL;


Final:

head
 |
 v

NULL <- [20] <-> [30] -> NULL


Step 3:

free(nodeToDelete);


===============================================================================

9. Delete last node
-------------------

Example:

NULL <- [10] <-> [20] <-> [30] -> NULL


Delete node 30.

nodeToDelete
     |
     v

    [30]


Step:

nodeToDelete->prev->next = NULL;


Final:

NULL <- [10] <-> [20] -> NULL


Then:

free(nodeToDelete);


===============================================================================

10. Delete middle node
----------------------

Example:

NULL <- [10] <-> [20] <-> [30] -> NULL


Delete node 20.

Before:

[10] <-> [20] <-> [30]


Step 1:

nodeToDelete->next->prev = nodeToDelete->prev;

This connects 30 back to 10.


Step 2:

nodeToDelete->prev->next = nodeToDelete->next;

This connects 10 forward to 30.


Final:

[10] <-> [30]


Then:

free(nodeToDelete);


===============================================================================

11. Search node
---------------

findNode() traverses the list from head to NULL.

Example:

Search value 20.

head
 |
 v

10 <-> 20 <-> 30 -> NULL


Traversal:

currentNode = 10
currentNode = 20  -> found

Returns the address of the node containing 20.

If the value is not found, the function returns NULL.


===============================================================================

12. Forward traversal
---------------------

Forward traversal uses next.

head
 |
 v

10 <-> 20 <-> 30 -> NULL


Output:

10 20 30


Code idea:

while (head != NULL)
{
    printf("%d ", head->data);
    head = head->next;
}


===============================================================================

13. Backward traversal
----------------------

Backward traversal uses prev.

First go to the last node:

10 <-> 20 <-> 30
               ^
               |
          currentNode


Then move backwards:

30 -> 20 -> 10


Output:

30 20 10


Code idea:

while (currentNode != NULL)
{
    printf("%d ", currentNode->data);
    currentNode = currentNode->prev;
}


===============================================================================

14. Reverse doubly linked list
------------------------------

Original:

NULL <- [10] <-> [20] <-> [30] -> NULL


Goal:

NULL <- [30] <-> [20] <-> [10] -> NULL


In a doubly linked list, reversing means:

next becomes prev
prev becomes next


For each node:

temp = currentNode->prev;

currentNode->prev = currentNode->next;
currentNode->next = temp;


Important:

After swapping next and prev, the original next node is now stored in:

currentNode->prev


Therefore traversal continues with:

currentNode = currentNode->prev;


===============================================================================

15. Example reverse step
------------------------

Original node:

prev        currentNode     next
 |              |             |
 v              v             v

[10] <------> [20] <------> [30]


Before swap:

currentNode->prev points to 10
currentNode->next points to 30


After swap:

currentNode->prev points to 30
currentNode->next points to 10


So the direction of the node has been reversed.


===============================================================================

16. Complexity
--------------

listLength()
O(n)

insertAt_nPosition()
O(n)

findNode()
O(n)

deleteNode()
O(1) if node pointer is already known

printList()
O(n)

printReverse()
O(n)

reverseList()
O(n)

freeList()
O(n)


Important:

deleteNode() itself is O(1), because it receives a direct pointer to the node.

But if you first call findNode(), then the full operation is:

findNode() + deleteNode()
O(n) + O(1) = O(n)


===============================================================================

17. Memory management rules
---------------------------

Traversal:
- no malloc()
- no free()

Insert:
- malloc()

Delete:
- free()

Reverse:
- no malloc()
- no free()
- only pointer rewiring

At the end of the program:
- free the whole list using freeList()


===============================================================================
*/


/* Draft

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

int listLength(struct Node* head){
    int length = 0;

    while(head != NULL){
        length++;
        head = head->next;
    }

    return length;
}

int insertAt_nPosition(struct Node** head, int value, int pos){
    int length = listLength(*head);

    if(pos < 0 || pos > length)
    {
        printf("Invalid position\n");
        return 0;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        return 0;
    }

    newNode->data = value;

    if(pos == 0){
        newNode->next = *head;
        newNode->prev = NULL;
        if(*head != NULL){ // falls head auf eine leere List zeigt sonst wird das Programm z.B (*head)->prev crashen
            (*head)->prev = newNode;
        }

        *head = newNode;
        return 1;
    }

    struct Node *currentNode = *head;

    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }

    newNode->prev->next = newNode;

    return 1;
}

void reverseList(struct Node** head){

    struct Node *currentNode = *head;
    struct Node *newHead = NULL;
    struct Node *temp = NULL;

    if(*head == NULL){ // Schutz gegen leere Liste
        return;
    }

    while (currentNode != NULL){
        temp = currentNode->prev;

        currentNode->prev = currentNode->next;
        currentNode->next = temp;
        newHead = currentNode; // um den neuen Head zu merken, der neue Head ist jetzt der Node der den letzen Node war

        currentNode = currentNode->prev;
    }

    *head = newHead;
}


void deleteNode(struct Node **head, struct Node* NodetoDelete)
{

    if (*head == NULL || NodetoDelete == NULL)
    {
        return;
    }

    if (NodetoDelete->prev == NULL){
        *head = NodetoDelete->next;

        if (*head != NULL){
        (*head)->prev = NULL;
    }
        free(NodetoDelete);
        return;
    }
    if (NodetoDelete->next == NULL){
        NodetoDelete->prev->next = NULL;

        free(NodetoDelete);
        return;
    }

    NodetoDelete->next->prev = NodetoDelete->prev;
    NodetoDelete->prev->next = NodetoDelete->next;
    free(NodetoDelete);
}


Node *findNode(struct Node *head, int value)
{
    struct Node *nodetoFind = head;

    while (nodetoFind != NULL)
    {
        if (nodetoFind->data == value)
        {
            return nodetoFind;
        }

        nodetoFind = nodetoFind->next;
    }

    return NULL;
}

void printReverse(struct Node *head){
    if (head == NULL)
    {
        printf("\n");
        return;
    }

    struct Node *currentNode = head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    }

    printf("\n");
}

void freeList(struct Node **head)
{
    struct Node *currentNode = *head;
    while (currentNode != NULL)
    {
        struct Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    *head = NULL;
}

void printList(struct Node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}


int main(){
    struct Node *head = NULL;
    int pos = 0;

    for (int i = 0; i < 6; i++){
        if(insertAt_nPosition(&head,(i*5),pos))
            pos++;
    }

    printList(head);

    printReverse(head);

    reverseList(&head);
    printList(head);

    struct Node* nodetoDelete = findNode(head, 15);
    deleteNode(&head, nodetoDelete);

    printList(head);

    if (insertAt_nPosition(&head, 99, 8)) // Einfügen in eine ungueltige Position
        printList(head);
}
*/
