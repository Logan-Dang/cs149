#include <stdio.h>

int main(int argc, char const *argv[])
{
  int input;
  printf("Enter an int:\n");
  scanf("%d", &input);
  while (input > 0)
  {
    printf("%d", input % 2);
    input /= 2;
  }
  return 0;
}
