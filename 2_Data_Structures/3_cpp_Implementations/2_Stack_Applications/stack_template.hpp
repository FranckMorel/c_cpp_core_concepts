/*
 * Topic: Generic Stack
 *
 * Generic stack implementation using a singly linked list.
 *
 * Supports any data type:
 *
 * - int
 * - char
 * - float
 * - SensorData
 * - User-defined types
 *
 * LIFO (Last In First Out)
 */

template <typename T>
class Stack
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

    /* Pointer to top element */
    Node *top;

public:
    /* Create an empty stack */
    Stack();

    /* Release all allocated nodes */
    ~Stack();

    /* Insert new element on top */
    void push(const T &data);     // const because : Read-only reference , data to be pushed in shouldn't be changed

    /* Remove top element */
    bool pop(T &data);

    /* Read top element without removing it */
    bool peek(T &data) const;    // const because : Read-only operation , Fxn does not modify the stack

    /* Check whether stack is empty */
    bool isEmpty() const;
};


/*
 * Constructor
 *
 * Creates an empty stack.
 */
template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}


/*
 * Destructor
 *
 * Frees all nodes to avoid memory leaks.
 */
template <typename T>
Stack<T>::~Stack()
{
    Node *currentNode = top;

    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;

        delete currentNode;

        currentNode = nextNode;
    }

    top = nullptr;
}


/*
 * Push Operation
 *
 * Inserts a new element
 * at the top of the stack.
 */
template <typename T>
void Stack<T>::push(const T &data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = top;

    top = newNode;
}


/*
 * Pop Operation
 *
 * Removes the top element and
 * returns it through the reference parameter.
 *
 * Returns:
 * true  -> success
 * false -> stack empty
 */
template <typename T>
bool Stack<T>::pop(T &data)
{
    if (top == nullptr)
    {
        return false;
    }

    Node *temp = top;

    data = top->data;

    top = temp->next;

    delete temp;

    return true;
}


/*
 * Peek Operation
 *
 * Reads the top element
 * without removing it.
 *
 * Returns:
 * true  -> success
 * false -> stack empty
 */
template <typename T>
bool Stack<T>::peek(T &data) const
{
    if (top == nullptr)
    {
        return false;
    }

    data = top->data;

    return true;
}


/*
 * Check whether stack is empty.
 */
template <typename T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}
