#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int eventId;
    int priority;
    int timestamp;

    struct Node* next;
};

void addEvent(struct Node** head, struct Node* event){
    struct Node* currentNode = *head;
    event->next = NULL;

    if(*head == NULL){
        *head = event;
         return;
    }
    while (currentNode->next != NULL) // add am Ende der Liste
    {
        currentNode = currentNode->next;
    }

    currentNode->next = event;
}


Node* findEvent(struct Node* head, int eventId)
{
    struct Node *currentNode = head;

    while(currentNode != NULL){
        if (currentNode->eventId == eventId)
        {
            return currentNode;
        }

        currentNode = currentNode->next;
    }

    return NULL;
}


void addEventbyPriority(struct Node** head, struct Node* event)
{
    struct Node *currentNode = *head;
    event->next = NULL;

    if (*head == NULL)
    {
        *head = event;
        return;
    }

    if (event->priority > (*head)->priority)
    {
        event->next = *head;
        *head = event;
         return;
    }

    while(currentNode != NULL)
    {
        if(currentNode->next == NULL)
        {
            event->next = currentNode->next;
            currentNode->next = event;
            return;
        }

        if(event->priority > currentNode->next->priority)
        {
            event->next = currentNode->next;
            currentNode->next = event;
            return;
        }

        currentNode = currentNode->next;
    }

}


void processNextEvent(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *eventToProcess = *head;

    printf("Processing Event %d ...\n", eventToProcess->eventId);

    *head = eventToProcess->next;

    free(eventToProcess);
}


void printList(struct Node* head)
{
        while (head != NULL)
        {
            printf("%d,%d,%d ", head->eventId, head->priority, head->timestamp);
            head = head->next;
        }

        printf("\n");
}


int main()
{
        struct Node* head = NULL;
        struct Node* event1 = (struct Node*)malloc(sizeof(struct Node));
        if (event1 == NULL)
        {
            return 1;
        }

        event1->eventId = 1;
        event1->priority = 5;
        event1->timestamp = 100;
        event1->next = NULL;

        addEvent(&head, event1);
        printList(head);
        printList(findEvent(head, event1->eventId));
}
