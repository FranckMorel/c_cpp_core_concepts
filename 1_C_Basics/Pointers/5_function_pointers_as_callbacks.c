/*
 * Topic: Function Pointers as Callback Functions
 *
 * This example demonstrates:
 * - how to pass a function pointer as an argument
 * - how callback functions can modify the behavior of another function
 * - how one generic function can be reused with different comparison logic
 *
 * Embedded relevance:
 * Callback functions are widely used in embedded systems for:
 * - interrupt handlers
 * - timer events
 * - UART receive callbacks
 * - driver event handling
 * - RTOS hooks
 * - state machine actions
 */

#include <stdio.h>

int compare_descending(int a, int b)
{
    /*
     * Return 1 if the two elements should be swapped.
     * This creates a descending order.
     */
    return a < b;
}

int compare_ascending(int a, int b)
{
    /*
     * Return 1 if the two elements should be swapped.
     * This creates an ascending order.
     */
    return a > b;
}

void bubble_sort(int *array, int size, int (*compare)(int, int))
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (compare(array[j], array[j + 1]))
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(const int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(void)
{
    int values[] = {3, 2, 1, 6, 5, 4};
    int size = sizeof(values) / sizeof(values[0]);

    printf("Original array: ");
    print_array(values, size);

    bubble_sort(values, size, compare_ascending);

    printf("Ascending order: ");
    print_array(values, size);

    bubble_sort(values, size, compare_descending);

    printf("Descending order: ");
    print_array(values, size);

    return 0;
}

/*
Draft
#include <stdio.h>

// Original function (comment before run)
void BubbleSort(int *A, int n){
    int i, j, temp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++){
            if(A[j] < A[j+1]){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }

        }
}


// Writing Function BubbleSort() using pointer callback

int compare(int a,int b)
{
  if(a<b)
      return 1;
  else
      return 0;
}

void BubbleSort(int* A,  int n, int(*p)(int,int))
{
    int i, j, temp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++){
            if (p(A[j],A[j+1])){ // in this way , you can decide of sort in icreasing or decreasing Order using compare Fxn
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
}

int main(){
        int A[] = {3, 2, 1, 6, 5, 4};

        BubbleSort(A, 6, compare);

        for (int i = 0; i < 6; i++)
            printf("%d ", A[i]);
}
*/
