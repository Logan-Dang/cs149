#include <stdio.h>

int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int smallest = a;
  if (b < smallest)
  {
    smallest = b;
  }
  if (c < smallest)
  {
    smallest = c;
  }
  printf("%d\n", smallest);

  return 0;
}
