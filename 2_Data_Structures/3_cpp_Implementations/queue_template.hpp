#ifndef QUEUE_TEMPLATE_HPP
#define QUEUE_TEMPLATE_HPP

/*
 * Topic: Generic Queue
 *
 * Generic queue implementation using a singly linked list.
 *
 * Supports any data type:
 *
 * - int
 * - char
 * - float
 * - SensorData
 * - User-defined types
 *
 * FIFO (First In First Out)
 */

template <typename T>
class Queue
{
private:
    /*
     * Internal node structure.
     *
     * Stores:
     * - data of type T
     * - pointer to next node
     */
    struct Node
    {
        T data;
        Node *next;
    };

    /*
     * front points to the first element
     * that will be removed.
     *
     * rear points to the last inserted element.
     */
    Node *front;
    Node *rear;

public:
    /* Create an empty queue */
    Queue();

    /* Release all allocated nodes */
    ~Queue();

    /*
     * Insert new element at the rear.
     *
     * const T&:
     * Read-only reference.
     * Avoids unnecessary copies and the
     * original data is not modified.
     */
    void enqueue(const T &data);

    /*
     * Remove the element at the front
     * and return it through reference.
     */
    bool dequeue(T &data);

    /*
     * Read the front element
     * without removing it.
     *
     * const:
     * Function does not modify the queue.
     */
    bool peek(T &data) const;

    /*
     * Check whether the queue is empty.
     *
     * const:
     * Read-only operation.
     */
    bool isEmpty() const;
};


/*
 * Constructor
 *
 * Creates an empty queue.
 */
template <typename T>
Queue<T>::Queue()
{
    front = nullptr;
    rear = nullptr;
}


/*
 * Destructor
 *
 * Frees all dynamically allocated nodes
 * to avoid memory leaks.
 */
template <typename T>
Queue<T>::~Queue()
{
    Node *currentNode = front;

    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;

        delete currentNode;

        currentNode = nextNode;
    }

    front = nullptr;
    rear = nullptr;
}


/*
 * Enqueue Operation
 *
 * Inserts a new element
 * at the rear of the queue.
 */
template <typename T>
void Queue<T>::enqueue(const T &data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = nullptr;

    /*
     * Special case:
     * Queue is currently empty.
     */
    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
        return;
    }

    /*
     * Link the current last node
     * to the new node.
     */
    rear->next = newNode;

    /*
     * Update rear so that it points
     * to the newly inserted node.
     */
    rear = newNode;
}


/*
 * Dequeue Operation
 *
 * Removes the first element
 * from the queue.
 *
 * Returns:
 * true  -> success
 * false -> queue empty
 */
template <typename T>
bool Queue<T>::dequeue(T &data)
{
    if (front == nullptr)
    {
        return false;
    }

    Node *temp = front;

    data = front->data;

    front = front->next;

    /*
     * If the last element was removed,
     * both pointers must represent
     * an empty queue.
     */
    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;

    return true;
}


/*
 * Peek Operation
 *
 * Reads the first element
 * without removing it.
 */
template <typename T>
bool Queue<T>::peek(T &data) const
{
    if (front == nullptr)
    {
        return false;
    }

    data = front->data;

    return true;
}


/*
 * Check whether queue is empty.
 */
template <typename T>
bool Queue<T>::isEmpty() const
{
    return (front == nullptr);
}

#endif
