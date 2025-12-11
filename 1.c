// Write a C program that creates a 2D dynamic array with 10 rows.
//  The number of rows is fixed (10), but the number of columns for each row must be decided by the user, one row at a time.
// Your program must:
// Ask the user 10 times to input an integer n.

// n represents how many columns will be allocated for that row.

// Dynamically allocate exactly n integers for that row.

// Fill the entire row with the row index, where indices start from 1.

// Row 1 should be filled with 1

// Row 2 should be filled with 2

// ...

// Row 10 should be filled with 10

// After all 10 inputs are processed, print the entire 2D array.

// Make sure memory is properly freed.
// Example Interaction
// Input:
// 5
// 3
// 4
// …
// Output:
// Row 1 → 1 1 1 1 1
// Row 2 → 2 2 2
// Row 3 → 3 3 3 3
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10

void allocateCol(int **arr, int row, int col)
{
    arr[row] = malloc(col * sizeof(int));
    if (arr == NULL)
    { // if memory not allocates (malloc)it returns null
        printf("ERROR! Memory allocation failed for row %d.", row);
        return;
    }
}
int main()
{
    int **arr = malloc(ROWS * sizeof(int *));
    int row_sizes[ROWS];
    if (arr == NULL)
    {
        printf("Memory allocation failed for main array.\n");
        return 1;
    }
    for (int i = 0; i < ROWS; i++)
    {
        int col;
        printf("Enter number of elements(col size for row %d):",i+1);
        scanf("%d", &col);
        row_sizes[i] = col;
        allocateCol(arr, i, col);

        for (int j = 0; j < col; j++)
        {
            arr[i][j] = i + 1;
        }
    }

    printf("\n--- Final 2D Array ---\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("Row %d ->", i + 1);
        // row size array for col size
        for (int j = 0; j < row_sizes[i]; j++)
        {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}