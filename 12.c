#include <stdio.h>
#include <limits.h>
int findmax(int *arr,int i,int size){
  if(i == size){
    return INT_MIN;
  }
 int restofmax = findmax(arr,i+1,size);
 if(restofmax < arr[i]){
    return arr[i];
 }else{
    return restofmax;
 }
}
int main(){
    int arr[]= {1,3,5,4,-1,-23,48,38,389,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d",findmax(arr,0,size));
    return 0;
}