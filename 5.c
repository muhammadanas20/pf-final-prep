// #include <stdio.h>

// // int count(int arr[][2],int col,int row,int maxrow,int maxcol,int i){
// //   if(row == maxrow){
// //     return i;
// //   }
// //   if(col == maxcol){
// //   return count(arr,0,row+1,maxrow,maxcol,i);
// //   }
// //   if(arr[row][col] == 1){
// //     i++;
// //   }
// //    return count(arr,col+1,row,maxrow,maxcol,i);
// // }
// typedef struct
// {
//   float price;
//   int type;
//   float finalPrice;
// } Car;
// int main()
// {
//   Car arr[3];
//   for (int i = 0; i < 3; i++)
//   {
//     printf("Enter price of %d car:", i + 1);
//     scanf("%f", &arr[i].price);
//     printf("Enter type of car %d \n1 for luxury,0 for non luxruy:", i + 1);
//     scanf("%d", &arr[i].type);
//     float duty = .15 * arr[i].price;
//     float salesTax;
//     if (arr[i].type == 1)
//     {
//       salesTax = .10 * arr[i].price;
//     }
//     else if (arr[i].type == 0)
//     {
//       salesTax = .065 * arr[i].price;
//     }
//     else
//     {
//       printf("Error invalid type!\n");
//       break;
//     }
//     arr[i].finalPrice = (arr[i].price + salesTax + duty);
//     arr[i].finalPrice += .75 * (arr[i].price + salesTax + duty); // seller pprofit
//     arr[i].finalPrice += .06 * (arr[i].price + salesTax + duty); // GST
//   }
//   // printing
//   for (int i = 0; i < 3; i++)
//   {
//     printf("\n-----------total bill of car %d-------------\n",i+1);
//     printf("capital price:%.2f\n", arr[i].price);
//     printf("Type:%s\n", (arr[i].type) ? "luxury" : "nonluxury");
//     printf("Final price:%.2f\n", arr[i].finalPrice);
//   }
// }
// #include <stdio.h>
// #include <string.h>
// void removeWordFromString(char str[], char word[], char neww[])
// {
//   for (int i = 0; str[i] != '\0'; i++)
//   {
//     neww[i] = str[i];
//   }
//   int len = strlen(word);
//   for (int j = 0; str[j] != '\0'; j++)
//   {
//     int index = strcspn(str, word);
//      if(index < strlen(neww) - len && index >= 0){
//       for (int i = index; str[i] != '\0'; i++)
//       {
//         neww[i] = neww[i + len];
//       }
//       j--;
//     }
//   }
// }
// int main()
// {
//   char str[100], neww[100], word[100];
//   printf("Enter string to remove a word from:");
//   gets(str);
//   printf("\nEnter the word you want removed: ");
//   gets(word);
//   removeWordFromString(str, word, neww);
//   printf("\nAfter word removed: %s\n", neww);
//   return 0;
// }
int main(){
  
}