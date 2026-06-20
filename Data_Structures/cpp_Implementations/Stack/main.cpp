#include "Stack.hpp"
#include <iostream>

int main()
{
    Stack stack;

    stack.push(3);
    stack.print();
    stack.push(12);
    stack.print();

    stack.push(5);
    stack.print();

    int value;

    if (stack.peek(value))
    {
        std::cout << "Top element: " << value << "\n";
    }

    while (stack.pop(value))
    {
        std::cout << "Popped: " << value << "\n";
        stack.print();
    }

    return 0;
}
