#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    void* P = (void*) malloc(size_t size)
    malloc() liefert void pointer (void*) deswegen wird der Rückgabewert gecastet ( ex: (int*) malloc())
    malloc() allocates memory on heap without initializing bytes
    */
    int *P = (int *) malloc(3*sizeof(int)); // allocate 3 integers on heap
    P[0] = 10;
    P[1] = 20;
    printf("%d", *P); // first int
    printf("%d", *(P+1)); // 2nd

    free(P);

    /*
    void P = (void*) calloc(size_t num, size_t size)
    calloc() has the fxn as malloc but it takes 2 arguments
    1st argument: number of elements
    2nd argument: size of one element
    calloc() allocates memory and iniziliazes bytes with 0
    */

    int *P = (int *) calloc(3, sizeof(int));

    /*
    realloc() changes the size of a memory block
    Used when more or less memory is needed later
    it takes 2 arguments
    1st argument: pointer to old memory block
    2nd argument: new size in bytes
    */
    P = (int*) realloc(P, 5 * sizeof(int));
}
