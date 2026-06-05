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


int insertAt_nPosition(struct Node **head, int value, int pos)
{
    int length = listLength(*head);
    struct Node *newNode;
    struct Node *currentNode = *head;
    int i = 0;

    if(pos == 0){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            return 0;
        }
        newNode->data = value;
        newNode->next = *head;
        *head = newNode;
        return 1;

    }if(pos < 0 || pos > length){
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


void deleteNode(struct Node **head, int pos)
{
    int length = listLength(*head);
    struct Node* currentNode = *head;
    struct Node* NodetoDelete;
    int i = 0;

    if(pos == 0){
        currentNode = *head;
        *head = (*head)->next;
        free(currentNode);
        return;

    }if(pos < 0 || pos > length){
        printf("Ungueltige Position\n");
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
    struct Node *head = NULL;

    for (int i = 1; i < 6; i++)
    {
       insertNode(&head, (i * 10));
    }

    printf("Old List: ");
    printList(head);
    printf("List length: %d", listLength(head));
    printf("\n\n");


    if (insertAt_nPosition(&head, 50,5 ))
    {

        printf("New List: ");
        printList(head);
        printf("List length: %d", listLength(head));
    }
}
