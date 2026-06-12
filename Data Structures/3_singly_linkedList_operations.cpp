/*
 * Topic: Singly Linked List Operations
 *
 * This example demonstrates:
 * - insert at head
 * - insert at a specific position
 * - delete at a specific position
 * - search by value
 * - reverse a linked list
 * - list traversal
 * - list length calculation
 * - safe dynamic memory handling
 *
 * NOTE:
 * See Extra Notes at the bottom for:
 * - pointer diagrams
 * - memory diagrams
 * - head pointer explanation
 * - insert/delete/reverse walkthroughs
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/*
 * Insert a new node at the beginning of the list.
 *
 * head  - address of the head pointer
 * value - value to insert
 */
int insertNode(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    return 1;
}

/*
 * Count the number of nodes in the list.
 *
 * This function does not modify the list.
 */
int listLength(struct Node *head)
{
    struct Node *currentNode = head;
    int length = 0;

    while (currentNode != NULL)
    {
        length++;
        currentNode = currentNode->next;
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

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = value;

    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return 1;
    }

    struct Node *currentNode = *head;

    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return 1;
}

/*
 * Delete a node at position pos.
 *
 * Valid delete positions:
 * 0 to length - 1
 */
int deleteNode(struct Node **head, int pos)
{
    int length = listLength(*head);

    if (pos < 0 || pos >= length)
    {
        printf("Invalid position\n");
        return 0;
    }

    struct Node *nodeToDelete;

    if (pos == 0)
    {
        nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
        return 1;
    }

    struct Node *currentNode = *head;

    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
    }

    nodeToDelete = currentNode->next;
    currentNode->next = nodeToDelete->next;

    free(nodeToDelete);

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
 * Reverse the linked list.
 */
void reverseList(struct Node **head)
{
    struct Node *previousNode = NULL;
    struct Node *currentNode = *head;
    struct Node *nextNode = NULL;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    *head = previousNode;
}

/*
 * Print all nodes.
 *
 * This function does not modify the original head.
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

    for (int i = 1; i < 6; i++)
    {
        insertNode(&head, i * 10);
    }

    printf("Original list: ");
    printList(head);
    printf("List length: %d\n\n", listLength(head));

    if (insertAt_nPosition(&head, 5, 5))
    {
        printf("List after insert: ");
        printList(head);
        printf("List length: %d\n\n", listLength(head));
    }

    if (deleteNode(&head, 3))
    {
        printf("List after delete: ");
        printList(head);
        printf("List length: %d\n\n", listLength(head));
    }

    struct Node *nodeToFind = findNode(head, 10);

    if (nodeToFind != NULL)
    {
        printf("Node found: %d\n\n", nodeToFind->data);
    }
    else
    {
        printf("No such node found\n\n");
    }

    reverseList(&head);

    printf("List after reverse: ");
    printList(head);

    freeList(&head);

    return 0;
}

/*
===============================================================================
EXTRA NOTES
===============================================================================

1. Node structure
-----------------

Each node contains:

[data | next]

data:
- stores the value

next:
- stores the address of the next node


Example:

[50 | *] -> [40 | *] -> [30 | NULL]


===============================================================================

2. Head pointer
---------------

head stores the address of the first node.

head
 |
 v

[50 | *] -> [40 | *] -> [30 | NULL]

If head is lost, the whole list becomes unreachable.


===============================================================================

3. Why some functions use Node* and others Node**
-------------------------------------------------

Read-only functions:

printList()
listLength()
findNode()

use:

struct Node *head

because they only traverse the list.


Modifying functions:

insertNode()
insertAt_nPosition()
deleteNode()
reverseList()

use:

struct Node **head

because they may change the real head pointer.


Example:

insert at head:

Before:

head
 |
 v

[50] -> [40] -> NULL


After inserting 10:

head
 |
 v

[10] -> [50] -> [40] -> NULL


The actual head pointer changed.
Therefore, the function needs access to the address of head.


===============================================================================

4. Insert at head
-----------------

Before:

head
 |
 v

[50 | *] -> [40 | NULL]


Step 1:
Allocate new node.

newNode
 |
 v

[ ? | ? ]


Step 2:
Store value.

newNode
 |
 v

[10 | ?]


Step 3:
Connect new node to old head.

newNode
 |
 v

[10 | *] -----> [50 | *] -> [40 | NULL]


Step 4:
Move head to new node.

head
 |
 v

[10 | *] -> [50 | *] -> [40 | NULL]


Code:

newNode->next = *head;
*head = newNode;


===============================================================================

5. Insert at position
---------------------

Example:

List:

Position:
0     1     2     3

50 -> 40 -> 30 -> 20 -> NULL

Insert 99 at position 2.

Target result:

50 -> 40 -> 99 -> 30 -> 20 -> NULL


Strategy:

1. Traverse to position pos - 1.
2. Store currentNode->next inside newNode->next.
3. Set currentNode->next to newNode.


Before:

currentNode
    |
    v

[40 | *] -----> [30 | *]


Insert:

newNode
 |
 v

[99 | ?]


Step 1:

newNode->next = currentNode->next;

[99 | *] -----> [30 | *]


Step 2:

currentNode->next = newNode;

[40 | *] -----> [99 | *] -----> [30 | *]


===============================================================================

6. Delete node at position
--------------------------

Example:

List:

Position:
0     1     2     3

50 -> 40 -> 30 -> 20 -> NULL

Delete position 2.

Node to delete:

[30]


Strategy:

1. Traverse to position pos - 1.
2. Save currentNode->next as nodeToDelete.
3. Connect currentNode->next to nodeToDelete->next.
4. Free nodeToDelete.


Before:

currentNode
    |
    v

[40 | *] -----> [30 | *] -----> [20 | NULL]


Step 1:

nodeToDelete = currentNode->next;

nodeToDelete
     |
     v

[30 | *]


Step 2:

currentNode->next = nodeToDelete->next;

[40 | *] ---------------------> [20 | NULL]


Step 3:

free(nodeToDelete);


Final:

50 -> 40 -> 20 -> NULL


===============================================================================

7. Delete first node
--------------------

Special case:

Delete position 0.

Before:

head
 |
 v

[50 | *] -> [40 | *] -> [30 | NULL]


Step 1:
Save old head.

nodeToDelete = *head;


Step 2:
Move head to next node.

*head = (*head)->next;


Now:

head
 |
 v

[40 | *] -> [30 | NULL]

nodeToDelete
     |
     v

[50 | *]


Step 3:
Free old head.

free(nodeToDelete);


===============================================================================

8. Search node
--------------

findNode() traverses the list from head to NULL.

Example:

Search value 30.

head
 |
 v

50 -> 40 -> 30 -> 20 -> NULL

Traversal:

currentNode = 50
currentNode = 40
currentNode = 30  -> found

Returns address of node containing 30.

If no node contains the value, the function returns NULL.


===============================================================================

9. Reverse list
---------------

Original:

head
 |
 v

50 -> 40 -> 30 -> NULL


Goal:

head
 |
 v

30 -> 40 -> 50 -> NULL


Three pointers are used:

previousNode
currentNode
nextNode


Initial state:

previousNode = NULL
currentNode  = head


Iteration 1:

nextNode = currentNode->next;

nextNode
 |
 v

40 -> 30 -> NULL


currentNode->next = previousNode;

50 -> NULL


previousNode = currentNode;
currentNode = nextNode;


Now:

previousNode
 |
 v

50 -> NULL

currentNode
 |
 v

40 -> 30 -> NULL


Iteration 2:

40 -> 50 -> NULL


Iteration 3:

30 -> 40 -> 50 -> NULL


At the end:

currentNode == NULL
previousNode points to the new first node.


Final step:

*head = previousNode;


===============================================================================

10. Complexity
--------------

listLength()
O(n)

printList()
O(n)

findNode()
O(n)

insertNode() at head
O(1)

insertAt_nPosition()
O(n)

deleteNode()
O(n)

reverseList()
O(n)


===============================================================================

11. Memory management rules
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

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

//struct Node *head = NULL;

void insertNode(struct Node** head,int value){
    struct Node* newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL){
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

}

int listLength(struct Node* head){
    struct Node *currentNode = head;
    int length = 0;

    while (currentNode != NULL)
    {
        length++;
        currentNode = currentNode->next;
    }
    return length;
}


int insertAt_nPosition(struct Node** head, int value, int pos)
{
    int length = listLength(*head);
    struct Node* newNode;
    struct Node* currentNode = *head;
    int i = 1;

    if(pos == 1){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            return 0;
        }
        newNode->data = value;
        newNode->next = *head;
        *head = newNode;
        return 1;

    }if(pos < 1 || pos > length){
            printf("Ungueltige Position\n");
            return 0;
    }

    while (currentNode != NULL){

        if (i == (pos - 1)){
            newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL)
            {
                return 0;
            }
            newNode->data = value;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return 1;
        }
        currentNode = currentNode->next;
        i++;
    }

    return 0;
}


void deleteNode(struct Node** head, int pos)
{
    int length = listLength(*head);
    struct Node* currentNode = *head;
    struct Node* NodetoDelete;
    int i = 0;

    if (pos < 0 || pos >= length){
        printf("Ungueltige Position\n");
        return;

    }if (pos == 0){
        NodetoDelete = *head;
        *head = (*head)->next;
        free(NodetoDelete);
        return;
    }

    while (currentNode != NULL)
    {
        if (i == (pos-1)){
            NodetoDelete = currentNode->next;
            currentNode->next = NodetoDelete->next;
            free(NodetoDelete);
            return;
        }
        currentNode = currentNode->next;
        i++;
    }
}

Node* findNode(Node* head, int value){
    Node* currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->data == value)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return 0;
}

void reverseList(Node** head){
    Node* currentNode = *head;
    Node* previousNode = NULL;
    Node* nextNode;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    *head = previousNode;
}


void printList(struct Node* head){
   // printf("List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main(){
    struct Node* head = NULL;

    for (int i = 1; i < 6; i++)
    {
       insertNode(&head, (i * 10));
    }

    printf("List: ");
    printList(head);
    printf("List length: %d", listLength(head));
    printf("\n\n");


    if (insertAt_nPosition(&head, 5, 2)){
        printf("List after insert: ");
        printList(head);
        printf("List length: %d", listLength(head));
        printf("\n\n");
    }else{
        printf("\n");
    }

    deleteNode(&head, 3);

    printf("List after delete: ");
    printList(head);
    printf("List length: %d", listLength(head));
    printf("\n\n");

    struct Node* nodetoFind = findNode(head, 10);

    if(nodetoFind != NULL)
    {
        printf("Node found: %d", nodetoFind->data);
    }else{
        printf("No such node found");
    }

    printf("\n\n");

    reverseList(&head);
    printf("List after reverse: ");
    printList(head);
}
*/
