#ifndef STACK_TEMPLATE_HPP
#define STACK_TEMPLATE_HPP


template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *top;

public:
    Stack();
    ~Stack();

    void push(const T& data);
    bool pop(T& data);
    bool peek(T& data) const;
    bool isEmpty() const;
};



template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    Node* currentNode = top;
    while(currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    top = nullptr;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

template <typename T>
bool Stack<T>::pop(T& data)
{
    if(top == nullptr)
    {
        return false;
    }

    Node *temp = top;

    data = top->data;
    top = temp->next;
    delete temp;

    return true;
}

template <typename T>
bool Stack<T>::peek(T& data) const
{
    if (top == nullptr)
    {
        return false;
    }

    data = top->data;
    return true;
}


template <typename T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}


#endif
