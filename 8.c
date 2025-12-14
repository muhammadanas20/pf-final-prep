#include <stdio.h>

void display(char grid[][5], int row, int col) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char Ocean[5][5] = {
        {'~','~','~','~','~'},
        {'~','~','~','~','~'},
        {'~','~','~','~','~'},
        {'~','~','~','~','~'},
        {'~','~','~','~','~'}
    };
    
    int shipx[6] = {0,2,2,0,1,2};
    int shipy[6] = {0,2,3,4,4,4};
    int x, y;

    while(1){
        printf("Enter coordinate: ");
        scanf("%d %d", &x, &y);

        if(x < 0 || x >= 5 || y < 0 || y >= 5) {
            printf("Invalid coordinate!\n");
            continue;
        }

        if(Ocean[x][y] == 'X' || Ocean[x][y] == 'O') {
            printf("Already tried this spot!\n");
            display(Ocean,5,5);
            continue;
        }

        int hit = 0;
        for(int i=0; i<6; i++){
            if(shipx[i] == x && shipy[i] == y){
                Ocean[x][y] = 'X';
                printf("Hit!\n");
                shipx[i] = -1; // mark ship as hit
                shipy[i] = -1;
                hit = 1;
                break;
            }
        }

        if(!hit){
            Ocean[x][y] = 'O';
            printf("Miss\n");
        }

        display(Ocean,5,5);

        // Check win
        int win = 1;
        for(int i=0;i<6;i++){
            if(shipx[i] != -1){
                win = 0;
                break;
            }
        }

        if(win){
            printf("You won!\n");
            break;
        }
    }

    return 0;
}
