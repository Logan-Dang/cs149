/**
 * @file countnames.c
 * @author Logan Dang (logandang100@gmail.com)
 * @brief This module reads lines from a file provided by the 
 * command-line arguments, then counts the number of times the 
 * lines occur and displays the result.
 * @date 2023-02-20 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

int main(int argc, char const *argv[])
{
  if (argv[1] == NULL)
  {
    return 0;
  }
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("error: cannot open file\n");
    return 1;
  }

  char **names = NULL;
  int *counts = NULL;
  int numberOfNames = 0;
  int maxNumberOfNames = 0;

  char name[MAX_NAME_LENGTH];
  int lineNumber = 0;
  while (fgets(name, MAX_NAME_LENGTH, fp) != NULL)
  {
    lineNumber++;
    if (name[0] == '\n')
    {
      fprintf(stderr, "Warning - Line %d is empty.\n", lineNumber);
      continue;
    }
    char *newline_ptr = strchr(name, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    int i;
    for (i = 0; i < numberOfNames; i++)
    {
      if (strcmp(name, names[i]) == 0)
      {
        counts[i]++;
        break;
      }
    }
    if (i == numberOfNames)
    {
      if (numberOfNames >= maxNumberOfNames)
      {
        maxNumberOfNames = maxNumberOfNames == 0 ? 1 : maxNumberOfNames * 2; // double max
        names = realloc(names, maxNumberOfNames * sizeof(char *));
        counts = realloc(counts, maxNumberOfNames * sizeof(int));
      }
      names[numberOfNames] = malloc((strlen(name) + 1) * sizeof(char));
      strncpy(names[i], name, strlen(name) + 1);
      counts[numberOfNames] = 1;
      numberOfNames++;
    }
  }

  fclose(fp);
  for (int i = 0; i < numberOfNames; i++)
  {
    printf("%s: %d\n", names[i], counts[i]);
  }

  return 0;
}
