#include <string.h>
#include <ctype.h>
#include <stdio.h>


void removeNonAlpha(char userString[], char userStringAlpha[])
{
  int ptr = 0;
  for (int i = 0; i < strlen(userString); i++)
  {
    if (isalpha(userString[i]))
    {
      userStringAlpha[ptr] = userString[i];
      ptr++;
    }
  }
}

int main(int argc, char const *argv[])
{
  char str[] = "Hello";
  char res[50];
  removeNonAlpha(str, res);
  printf("%s\n", res);

  return 0;
}
