#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int eventId;
    int priority;
    int timestamp;

    struct Node* next;
};

struct Node* createEvent(int eventId, int priority, int timestamp){
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


int findEvent(struct Node *head, struct Node* event)
{
    struct Node *currentNode = head;

    while(currentNode != NULL){
        if (currentNode->eventId == event->eventId)
        {
            return currentNode->eventId;
        }

        currentNode = currentNode->next;
    }

    return 0;
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
        struct Node *event1 = createEvent(3851, 5, 100);
        struct Node *event2 = createEvent(3862, 2, 101);
        struct Node *event3 = createEvent(3932, 4, 105);
        struct Node *event4 = createEvent(3294, 3, 107);

        addEventbyPriority(&head, event1);
        addEventbyPriority(&head, event2);
        addEventbyPriority(&head, event3);
        addEventbyPriority(&head, event4);

        printf("Event found: %d", findEvent(head, event3));
        printf("\n\n");

        printEventList(head);
        processNextEvent(&head);
        printf("\n");
        printEventList(head);
}
