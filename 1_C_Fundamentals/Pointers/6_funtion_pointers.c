/*
 * Topic: Function Pointers
 *
 * This example demonstrates:
 * - how to declare function pointers
 * - how to assign a function address to a function pointer
 * - how to call a function through a pointer
 *
 * Embedded relevance:
 * Function pointers are commonly used in embedded systems for:
 * - callback functions
 * - interrupt handling
 * - driver interfaces
 * - event dispatchers
 * - state machine actions
 */


#include <stdio.h>

int Add(int a, int b){

    return a + b;
}

void printHello(const char* name){

    printf("Hello %s\n", name);
}

int main(){
    int result;

    /*
     * Function pointer to a function with:
     * - return type: int
     * - parameters: int, int
     */
    int (*p)(int, int); // without the paranthesis *p(int,int) -> this would be declaring a fxn that returns int*

    p = Add; // or simply p = Add , would return the Address of the Fxn
    result = p(2, 3); // or c = p(2,3) dereferencing and executing the Fxn

    printf("%d\n", result);

    char c[] = "John";
    /*
     * Function pointer to a function with:
     * - return type: void
     * - parameter: const char*
     */
    void (*prt)(const char*);
    prt = printHello;
    prt(c);
}
