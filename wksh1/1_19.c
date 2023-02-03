#include <stdio.h>

int main(void)
{
   int userNum;
   int userNum2;

   printf("Enter integer:\n");
   scanf("%d", &userNum);
   /* Type your code here. */
   printf_s("You entered: %d\n", userNum);
   printf_s("4 squared is %d\n", userNum * userNum);
   printf_s("And 4 cubed is %d!!\n", userNum * userNum * userNum);
   printf_s("Enter another integer:\n");
   scanf("%d", &userNum2);
   printf_s("%d + %d is %d\n", userNum, userNum2, userNum + userNum2);
   printf_s("%d * %d is %d\n", userNum, userNum2, userNum * userNum2);
   return 0;
}