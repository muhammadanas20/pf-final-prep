#include <stdio.h>
#define row 5
#define col 5
int valid(int grid[row][col], int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return 0;
    return (grid[r][c] == -1);
}
int main()
{
   int grid[row][col] = {
        {-1,  0, -1,  0,  0},
        { 0,  0,  0, -1,  0},
        { 0, -1,  0,  0,  0},
        {-1,  0,  0, -1, -1},
        { 0,  0,  0,  0,  0}
    };
    int result[row][col];

    // Copy initial grid
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = grid[i][j];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == -1)
                continue;

            int count = 0;
            count += valid(grid, i, j + 1);
            count += valid(grid, i, j - 1);
            count += valid(grid, i - 1, j);
            count += valid(grid, i + 1, j);
            count += valid(grid, i - 1, j - 1);
            count += valid(grid, i - 1, j + 1);
            count += valid(grid, i + 1, j - 1);
            count += valid(grid, i + 1, j + 1);

            result[i][j] = count;
        }
    }
    printf("====after====\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}