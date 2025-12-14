#include <stdio.h>
long long power(int base,int exp){
    if(exp == 0){
        return 1;
    }
    if(exp == 1) return base;
    long long half = power(base,exp/2);
    if(exp%2 == 0){
        return half*half;
    }
    else{
        return base*half*half;
    }
}
void encrypt(char *msg, int shift){
    if(*msg == '\0') return;
    *msg += shift;
    return encrypt(msg+1,shift);

}
int countpath(int r,int c){
    if (r>=3 || c>=3 || r < 0 || c < 0){
        return 0;
    }
    if(r == 2 && c == 2){
        return 1;
    }
    return countpath(r+1,c) + countpath(r,c+1);
}
void expand(char *str){
    if (*str == '\0') return;
    if(*(str+1) == '\0') return;
    int len = *(str+1) - '0';
    for(int i=0;i<len;i++){
        printf("%c",*str);
    }
    expand(str+2);
}
int main(){
  printf("%lld\n",power(5,2));
  char str[] = "H1L3O5";
//   encrypt(str,3);
//   printf("%s\n",str);
//  printf("%d",str);
expand(str);
 
}