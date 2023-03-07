/**
* @file countnames_parallel.c
* @author Logan Dang
* @brief This module reads lines from multiple files provided by the
* command-line arguments, then counts the number of times the
* lines occur and displays the result.
* @date 2023-03-06
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_NAME_LENGTH 100


int count_names(const char *filename, int pipe_fd[2])
{
   FILE *fp = fopen(filename, "r");
   if (fp == NULL)
   {
       printf("error: cannot open file %s\n", filename);
       return 1;
   }


   char name[MAX_NAME_LENGTH];
   int lineNumber = 0;
   while (fgets(name, MAX_NAME_LENGTH, fp) != NULL)
   {
       lineNumber++;
       if (name[0] == '\n')
       {
           fprintf(stderr, "Warning - Line %d in %s is empty.\n", lineNumber, filename);
           continue;
       }
       char *newline_ptr = strchr(name, '\n');
       if (newline_ptr != NULL)
       {
           *newline_ptr = '\0';
       }


       // Send the name through the pipe to the parent process
       write(pipe_fd[1], name, strlen(name) + 1);
   }


   // Send an empty name to indicate end of file
   write(pipe_fd[1], "", 1);


   fclose(fp);
   return 0;
}


int main(int argc, char const *argv[])
{
   if (argc < 2)
   {
       printf("Usage: %s file1 [file2 ...]\n", argv[0]);
       return 0;
   }


   // Create pipes for each child process
   int pipes[argc - 1][2];
   for (int i = 0; i < argc - 1; i++)
   {
       if (pipe(pipes[i]) == -1)
       {
           perror("pipe");
           exit(1);
       }
   }


   // Create child processes
   pid_t pids[argc - 1];
   for (int i = 0; i < argc - 1; i++)
   // for every file index i
   {
       pid_t pid = fork();
       if (pid == -1)
       {
           fprintf(stderr, "Error forking.");
           return 1;
       }
       if (pid == 0)
       {
           // Child process
           close(pipes[i][0]); // Close the read end of the pipe
           count_names(argv[i + 1], pipes[i]);
           close(pipes[i][1]); // Close the write end of the pipe
           return 0;
       }
       pids[i] = pid;
   }


   // Parent process
   // Close the write end of all pipes
   for (int i = 0; i < argc - 1; i++)
   {
       close(pipes[i][1]);
   }


   // Read names from pipes and count them
   char **names = NULL;
   int *counts = NULL;
   int numberOfNames = 0;
   int maxNumberOfNames = 0;


   for (int i = 0; i < argc - 1; i++)
   {
       char name[MAX_NAME_LENGTH];
       int n;


       while ((n = read(pipes[i][0], name, MAX_NAME_LENGTH)) > 0)
       {
           if (strlen(name) == 0) {
               continue;
           }


           // Count the name
           int j;
           for (j = 0; j < numberOfNames; j++)
           {
               if (strcmp(name, names[j]) == 0)
               {
                   counts[j]++;
                   break;
               }
           }
           if (j == numberOfNames)
           {
               if (numberOfNames >= maxNumberOfNames)
               {
                   maxNumberOfNames = maxNumberOfNames == 0 ? 1 : maxNumberOfNames * 2; // double max
                   names = realloc(names, maxNumberOfNames * sizeof(char *));
                   counts = realloc(counts, maxNumberOfNames * sizeof(int));
               }
               names[numberOfNames] = malloc((strlen(name) + 1) * sizeof(char));
               strncpy(names[numberOfNames], name, strlen(name) + 1);
               counts[numberOfNames] = 2;
               numberOfNames++;
           }
       }


       if (n == -1)
       {
           perror("read");
           exit(1);
       }


       // Wait for child process to finish
       int status;
       if (waitpid(pids[i], &status, 0) == -1)
       {
           perror("waitpid");
           exit(1);
       }
       if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
       {
           printf("Child process %d exited with error code %d\n", pids[i], WEXITSTATUS(status));
       }
   }


   // Print the results
   for (int i = 0; i < numberOfNames; i++)
   {
       printf("%s: %d\n", names[i], counts[i]);
   }


   // Free memory
   for (int i = 0; i < numberOfNames; i++)
   {
       free(names[i]);
   }
   free(names);
   free(counts);


   return 0;
}