#include <stdio.h>
void fun(int n){
    if(n <= 0){
        return ;
    }
    fun(n-1);
    printf("%d ,",n);
}
int power(int p,float exp){
    if(exp == 0){
        return 1;
    }
    return p*power(p,exp-1);
}
int main() {
    int x = 10;
    int *y = &x;
    int **z = &y;
    
    int arr[] = {2, 4, 6, 8};
    int *p = arr;
    
    // // What prints here?
    // printf("%d %d\n", **z, *(*z));
    
    // // What prints here? (Pre-increment vs Post-increment on pointers)
    // printf("%d\n", *(++p)); 
    // printf("%d\n", *(p++)); 
    fun(5);
    printf("\n%d",power(4,3/2));
    
    return 0;
}