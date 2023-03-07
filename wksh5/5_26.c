#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char string[100];
  scanf("%s", &string);
  int length = 0;
  for (int i = 0; i < strlen(string); i++)
  {
    if (string[i] != ' ' && string[i] != '.' && string[i] != '!' && string[i] != ',')
    {
      length++;
    }
  }
  printf("Length of string %d\n", length);
  return 0;
}
