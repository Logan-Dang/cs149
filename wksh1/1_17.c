#include <stdio.h>

int main(void)
{
  int baseInt;
  int headInt;

  /* Type your code here. */
  scanf("%d %d", &baseInt, &headInt);
  printf_s("    %d\n", headInt);
  printf_s("    %d%d\n", headInt, headInt);
  printf_s("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
  printf_s("%d%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt, headInt);
  printf_s("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
  printf_s("    %d%d\n", headInt, headInt);
  printf_s("    %d\n", headInt);

  return 0;
}