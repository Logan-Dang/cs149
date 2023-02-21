#include <stdio.h>

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    return 0;
  }
  for (int i = argc - 1; i >= 2; i--) 
  {
    printf("%s, ", argv[i]);
  }
}
