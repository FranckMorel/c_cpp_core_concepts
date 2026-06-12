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

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

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
    struct Node *temp = NULL;

    while (currentNode != NULL){
        temp = currentNode->prev;

        currentNode->prev = currentNode->next;
        currentNode->next = temp;

        currentNode = currentNode->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

void printReverse(struct Node *head){

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

    if (insertAt_nPosition(&head, 99, 8)) // Einfügen in eine ungueltige Position
        printList(head);
}
