#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  float sum = 0;
  int max = 0;
  if (argc < 2)
  {
    return 0;
  }
  for (int i = 2; i < argc; i++) 
  {
    int input = atoi(argv[i]);
    sum += input;
    if (input > max) 
    {
      max = input;
    }
  }
  printf("%d %0.2lf\n", max, sum / (argc - 2));
  return 0;
}
