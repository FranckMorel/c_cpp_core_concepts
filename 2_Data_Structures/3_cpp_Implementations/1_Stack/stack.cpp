/*
Topic : CPP implementation of stack using linked List

See C implementation/stack for detail explanations for each function
*/

#include "stack.hpp"
#include <iostream>


Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    while(top != nullptr)
    {
        Node *nextNode = top->next;
        delete top;
        top = nextNode;
    }
}

void Stack::push(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

bool Stack::pop(int &value)
{
    if(top == nullptr)
    {
        return false;
    }

    Node *temp = top;
    value = temp->data;

    top = temp->next;
    delete temp;
    return true;
}

bool Stack::peek(int &value) const
{
    if (top == nullptr)
    {
        return false;
    }

    value = top->data;
    return true;
}

bool Stack::isEmpty() const
{
    return (top == nullptr);
}

void Stack::print() const
{
    if(top == nullptr)
    {
        std::cout << "Stack is empty\n";
        return;
    }

    Node *currentNode = top;

    while(currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }

    std::cout << "\n";
}
