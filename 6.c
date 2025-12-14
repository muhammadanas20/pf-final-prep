#include <stdio.h>
#define Maxcol 5
#define Maxrow 5
typedef struct
{
    int x;
    int y;
} position;
void display(int arr[][Maxcol], position *player)
{
    printf("====================\n");
    for (int i = 0; i < Maxrow; i++)
    {
        for (int j = 0; j < Maxrow; j++)
        {
            if (i == player->x && j == player->y)
            {
                printf("_");
            }
            else
            {
                printf("%d", arr[i][j]);
            }
        }
        printf("\n");
    }
}
int moveup(int arr[][Maxcol], position *player)
{
    if (player->x != 0)
    {
           if (arr[player->x-1][player->y] == 1)
        {
            return 0;
        }
        else
        {
             player->x -= 1;
            return 1;
        }
    }
    return 0;
}
int movedown(int arr[][Maxcol], position *player)
{
    if (player->y != Maxrow - 1)
    {
        
          if (arr[player->x][player->y+1] == 1)
        {
            return 0;
        }
        else
        { player->y += 1;
            return 1;
        }
    }
    return 0;
}
int moveleft(int arr[][Maxcol], position *player)
{
    if (player->y != 0)
    {
           if (arr[player->x][player->y-1] == 1)
        {
            return 0;
        }
        else
        {
            player->y -= 1;
            return 1;
        }
    }
    return 0;
}
int moveright(int arr[][Maxcol], position *player)
{
    if (player->x != Maxcol - 1)
    {
        if (arr[player->x + 1][player->y] == 1)
        {
            return 0;
        }
        else
        {
            player->x += 1;
            return 1;
        }
    }
    return 0;
}

int wincheck(int arr[][Maxcol], position player)
{
    if (player.x == Maxrow - 1 && player.y == Maxcol - 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int moves = 0;
    position player;
    // intial position
    int arr[Maxrow][Maxcol] = {{0, 1, 0, 1, 1}, {0, 0, 0, 1, 1}, {1, 0, 1, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 0}};
    player.x = 0;
    player.y = 0;
    while (1)
    {
        int choice;
        printf("1.Up\n2.Down\n3.left\n4.right\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (moveup(arr, &player))
            {
                if (wincheck(arr, player))
                {
                    printf("You won!");
                    break;
                }
                else
                {

                    continue;
                }
                moves++;
            }
            else
            {
                printf("Bloked!\n");
                display(arr, &player);
            }
            break;
        case 2:
            if (movedown(arr, &player))
            {
                if (wincheck(arr, player))
                {
                    printf("You won!");
                    break;
                }
                else
                {
                    continue;
                }
                moves++;
            }

            else
            {
                printf("Bloked!\n");
                display(arr, &player);
            }
            break;
        case 3:
            if (moveleft(arr, &player))
            {
                if (wincheck(arr, player))
                {
                    printf("You won!");
                    break;
                }
                else
                {
                    continue;
                }
                moves++;
            }
            else
            {
                printf("Bloked!\n");
                display(arr, &player);
            }
            break;
        case 4:
            if (moveright(arr, &player))
            {
                if (wincheck(arr, player))
                {
                    printf("You won!");
                    break;
                }
                else
                {
                    continue;
                }
                moves++;
            }
            else
            {
                printf("Bloked!\n");
                display(arr, &player);
            }
            break;
        }
    }
    printf("\ntotal moves %d", moves);
}