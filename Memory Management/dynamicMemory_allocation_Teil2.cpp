// pratical example using dynamic momory allocation

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of Array\n");
    scanf("%d", &n);

    int *P = (int *)malloc(n * sizeof(int));
    // or int *P = (int *)calloc(n , sizeof(int));

    for (int i = 0; i < n; i++)
    {
        P[i] = i + 1;
    }

    for (int j = 0; j < n; j++)
    {
        printf("%d ", P[j]);
    }
}
