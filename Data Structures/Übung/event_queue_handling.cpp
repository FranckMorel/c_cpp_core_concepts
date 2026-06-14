#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int eventId;
    int priority;
    int timestamp;

    struct Node* next;
};

Node* creatEvent(int eventId, int priority, int timestamp){
    struct Node* newEvent = (struct Node *)malloc(sizeof(struct Node));
    if (newEvent == NULL)
    {
        return NULL;
    }

    newEvent->eventId = eventId;
    newEvent->priority = priority;
    newEvent->timestamp = timestamp;

    newEvent->next = NULL;

    return newEvent;
}

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


void printEventList(struct Node* head)
{
        while (head != NULL)
        {
            printf("%d, %d, %d \n", head->eventId, head->priority, head->timestamp);
            head = head->next;
        }

        printf("\n");
}


int main()
{
        struct Node* head = NULL;
        struct Node *event1 = creatEvent(3851, 5, 100);
        struct Node *event2 = creatEvent(3862, 2, 101);
        struct Node *event3 = creatEvent(3932, 4, 105);
        struct Node *event4 = creatEvent(3294, 3, 107);

        addEventbyPriority(&head, event1);
        addEventbyPriority(&head, event2);
        addEventbyPriority(&head, event3);
        addEventbyPriority(&head, event4);

        printEventList(head);
        // printList(findEvent(head, event1->eventId));
}
