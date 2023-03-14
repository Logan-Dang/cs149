#include <stdio.h>

int main(int argc, char const *argv[])
{
  int arr[100];
  int i = 0;
  while (scanf("%d", &arr[i]) == 1)
  {
    i++;
  }
  int every = 1;
  int any = 0;
  for (int j = 0; j < i; j++) {
    if (arr[j] % 10 == 0) {
      any = 1;
    } else {
      every = 0;
    }
    if (any == 1 && every == 0) {
      printf("Mixed values.\n");
      return 0;
    }
  }
  if (every == 1) {
    printf("Every number was a multiple of 10.\n");
  }
  if (any == 0) {
    printf("None of the numbers were a multiple of 10.\n");
  }

    return 0;
}
