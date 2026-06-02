/*
 * Topic: Arrays vs Linked Lists
 *
 * This example demonstrates:
 * - memory layout differences
 * - access cost
 * - insertion at the beginning
 * - why arrays and linked lists solve different problems
 *
 * Embedded relevance:
 * Arrays are predictable and cache-friendly.
 * Linked lists are flexible, but require pointer handling,
 * dynamic allocation and careful memory management.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print_array(int *array, int size)
{
    printf("Array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void print_array_addresses(int *array, int size)
{
    printf("Array addresses:\n");

    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %d at %p\n", i, array[i], (void *)&array[i]);
    }

    printf("\n");
}

void insert_array_at_beginning(int *array, int *size, int capacity, int value)
{
    if (*size >= capacity)
    {
        printf("Array is full. Cannot insert %d\n", value);
        return;
    }

    /*
     * Elements must be shifted to the right.
     */
    for (int i = *size; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = value;
    (*size)++;
}

struct Node *insert_linked_list_at_beginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Node allocation failed\n");
        return head;
    }

    newNode->data = value;

    /*
     * Connect new node to the current first node.
     */
    newNode->next = head;

    /*
     * Return new head.
     */
    return newNode;
}

void print_linked_list(struct Node *head)
{
    printf("Linked List: ");

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void print_linked_list_addresses(struct Node *head)
{
    printf("Linked list node addresses:\n");

    while (head != NULL)
    {
        printf("Node data = %d at %p -> next = %p\n", head->data, (void *)head, (void *)head->next);

        head = head->next;
    }

    printf("\n");
}

int get_array_element(int *array, int index)
{
    return array[index];
}

int get_linked_list_element(struct Node *head, int index)
{
    struct Node *current = head;

    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            printf("Index out of range\n");
            return -1;
        }

        current = current->next;
    }

    if (current == NULL)
    {
        printf("Index out of range\n");
        return -1;
    }

    return current->data;
}

void free_linked_list(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main(void)
{
    /*
     * ARRAY EXAMPLE
     */

    int arrayCapacity = 6;
    int arraySize = 4;
    int array[6] = {20, 30, 40, 50};

    print_array(array, arraySize);
    print_array_addresses(array, arraySize);

    printf("Access array[2]: %d\n\n", get_array_element(array, 2));

    insert_array_at_beginning(array, &arraySize, arrayCapacity, 10);

    printf("After inserting 10 at beginning:\n");
    print_array(array, arraySize);
    printf("\n");

    /*
     * LINKED LIST EXAMPLE
     */

    struct Node *head = NULL;

    head = insert_linked_list_at_beginning(head, 50);
    head = insert_linked_list_at_beginning(head, 40);
    head = insert_linked_list_at_beginning(head, 30);
    head = insert_linked_list_at_beginning(head, 20);

    print_linked_list(head);
    print_linked_list_addresses(head);

    printf("Access linked_list[2]: %d\n\n", get_linked_list_element(head, 2));

    head = insert_linked_list_at_beginning(head, 10);

    printf("After inserting 10 at beginning:\n");
    print_linked_list(head);
    print_linked_list_addresses(head);

    free_linked_list(head);

    return 0;
}

/*
 * Extra Notes
 *
 * 1. Array memory layout
 *
 * Array:
 *
 * [20][30][40][50]
 *
 * Array elements are stored next to each other in contiguous memory.
 *
 * If int uses 4 bytes and the base address is 1000:
 *
 * array[0] -> 1000
 * array[1] -> 1004
 * array[2] -> 1008
 * array[3] -> 1012
 *
 * Address of array[i]:
 *
 * base_address + i * sizeof(int)
 *
 * Therefore:
 *
 * array[i] access -> O(1)
 *
 *
 * 2. Linked list memory layout
 *
 * Linked list:
 *
 * head
 *  |
 *  v
 *
 * [20 | next] -> [30 | next] -> [40 | next] -> [50 | NULL]
 *
 * Nodes do not need to be stored next to each other.
 *
 * Example:
 *
 * [20 | 0x5000] at 0x1000
 * [30 | 0x9000] at 0x5000
 * [40 | 0x3000] at 0x9000
 * [50 | NULL  ] at 0x3000
 *
 * The next pointer connects the nodes logically.
 *
 *
 * 3. Access cost
 *
 * Array:
 *
 * array[2]
 *
 * Direct address calculation.
 *
 * Cost:
 * O(1)
 *
 *
 * Linked List:
 *
 * To access index 2:
 *
 * start at head
 * move to next node
 * move to next node again
 *
 * Cost:
 * O(n)
 *
 *
 * 4. Insert at beginning - Array
 *
 * Before:
 *
 * [20][30][40][50][ ][ ]
 *
 * Insert 10 at beginning:
 *
 * Step 1:
 * Shift elements to the right.
 *
 * [ ][20][30][40][50][ ]
 *
 * Step 2:
 * Store 10 at index 0.
 *
 * [10][20][30][40][50][ ]
 *
 * Cost:
 * O(n)
 *
 *
 * 5. Insert at beginning - Linked List
 *
 * Initial list:
 *
 * head
 *  |
 *  v
 *
 * [20|*] ---> [30|*] ---> [40|NULL]
 *
 *
 * Step 1:
 * Allocate a new node.
 *
 * newNode
 *  |
 *  v
 *
 * [? | ?]
 *
 *
 * Step 2:
 * Store the value.
 *
 * newNode
 *  |
 *  v
 *
 * [10 | ?]
 *
 *
 * Step 3:
 * Connect the new node to the current head.
 *
 * Execute:
 *
 * newNode->next = head;
 *
 * Result:
 *
 * newNode
 *  |
 *  v
 *
 * [10|*]
 *    |
 *    +------> [20|*] ---> [30|*] ---> [40|NULL]
 *
 * head
 *  |
 *  v
 *
 * [20|*] ---> [30|*] ---> [40|NULL]
 *
 *
 * Important:
 *
 * At this point, head still points to [20|*].
 * The new node is connected to the old list,
 * but it is not yet the first node.
 *
 *
 * Step 4:
 * Move head to the new node.
 *
 * Execute:
 *
 * head = newNode;
 *
 * Result:
 *
 * head
 *  |
 *  v
 *
 * [10|*] ---> [20|*] ---> [30|*] ---> [40|NULL]
 *
 *
 * Cost:
 * O(1)
 *
 *
 * 6. Why return the new head?
 *
 * Function:
 *
 * struct Node *insert_linked_list_at_beginning(struct Node *head, int value)
 *
 * The function receives a copy of the head pointer.
 *
 * Therefore, changing head inside the function does not automatically
 * change the head variable in main().
 *
 * That is why the function returns the new head:
 *
 * head = insert_linked_list_at_beginning(head, 10);
 *
 *
 * 7. Memory cost
 *
 * Array:
 *
 * stores only data
 *
 * Linked List:
 *
 * stores:
 * - data
 * - pointer to next node
 *
 * Therefore, every linked list node needs extra memory.
 *
 *
 * 8. Embedded perspective
 *
 * Arrays are often preferred when:
 *
 * - maximum size is known
 * - deterministic memory usage is required
 * - fast random access is important
 * - dynamic allocation should be avoided
 *
 * Linked lists are useful when:
 *
 * - size changes during runtime
 * - frequent insertion/deletion is needed
 * - data does not need random access
 *
 * But linked lists require careful memory management:
 *
 * - malloc()
 * - free()
 * - avoiding memory leaks
 * - avoiding dangling pointers
 * - avoiding heap fragmentation
 */
