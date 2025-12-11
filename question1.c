#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    printf("Enter number of integers you to store:");
    scanf("%d", &N);
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL)
    { // if memory not allocates (malloc)it returns null
        printf("ERROR! Memory allocation failed.");
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        printf("Enter %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // display all array element
    printf("\nYou entered: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ,", arr[i]);
    }
    free(arr);
    return 0;
}