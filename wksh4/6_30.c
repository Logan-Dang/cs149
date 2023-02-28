#include <stdio.h>

int maxNumber(int a, int b, int c, int d)
{
  int res = a;
  if (res < b)
    res = b;
  if (res < c)
    res = c;
  if (res < d)
    res = d;
  return res;
}

int minNumber(int a, int b, int c, int d)
{
  int res = a;
  if (res > b)
    res = b;
  if (res > c)
    res = c;
  if (res > d)
    res = d;
  return res;
}

int main(int argc, char const *argv[])
{
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  printf("Max: %d\n", maxNumber(a, b, c, d));
  printf("Min: %d\n", minNumber(a, b, c, d));
  return 0;
}
