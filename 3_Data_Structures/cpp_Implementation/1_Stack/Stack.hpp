#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *top;

public:
    Stack();
   ~Stack();

    void push(int value);
    bool pop(int &value);
    bool peek(int &value) const;
    bool isEmpty() const;
    void print() const;
};

#endif
