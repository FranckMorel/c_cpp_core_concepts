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
        if(*head != NULL){ // falls head auf eine leere List zeigt sonst wird das Programm z.B *head->prev crashen
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

void printList(struct Node *head)
{
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

    //if(insertAt_nPosition(&head, -1, 3))
      //  printList(head);

    int length = listLength(head);
    printf("%d", length);
}
