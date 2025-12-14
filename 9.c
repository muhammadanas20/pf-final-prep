#include <stdio.h>
#include <string.h>
int ispalindorme(char *str,int start,int end){
 if(start >= end){
    return 1;
 }
 if(str[start] != str[end]){
    return 0;
 }
 ispalindorme(str,start+1,end-1);
}
int countChar(char *str, char target){
    if (*str == '\0') return 0;
    int count =0;
    if(*str == target)count++;
    return count + countChar(str+1,target);}
int main(){

   char  str[] = "smadams";
   printf("%d",ispalindorme(str,0,strlen(str)-1));
   printf("\n%d",countChar(str,'d'));
}