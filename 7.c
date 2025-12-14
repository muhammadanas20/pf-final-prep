#include <stdio.h>
#define col 3
#define row 3
void floodfill(int grid[][col],int x,int y,int old,int new){
     if(x > row-1 || x <0){
        return;
     }
     if(y >col-1 || y< 0){
        return;
     }
     if(grid[x][y] !=  old){
        return;
     } else{
         grid[x][y] = new;
     }
     //top
     floodfill(grid,x-1,y,old,new);
     //bottom
     floodfill(grid,x+1,y,old,new);
     //left
     floodfill(grid,x,y-1,old,new);
     //right
     floodfill(grid,x,y+1,old,new);
}
int main(){
    int grid[row][col]={
        {0,0,0},
        {1,1,1},
        {0,0,0}
    };
    int new,i,j;
    scanf("%d %d",&i,&j);
    scanf("%d",&new);
    floodfill(grid,i,j,grid[i][j],new);
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        printf("%d ",grid[i][j]);
    }
    printf("\n");
   }
 
}