/* This is where you implement the core solution.
   by <Name>, <Date>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include "./processes.h"


int main(int argc, char *argv[]){

  if(argc != 4){
    printf("%s\n", "Unexpected number of arguments");
    exit(-1);
  }

  int createNumChildren = atoi(argv[1]);
  int delayMicroseconds = atoi(argv[2]);
  char* fileName = argv[3];

  int numChildrenCreated = 0;
  int index = numChildrenCreated;
  ProcessInfo* processInfo = (ProcessInfo*) malloc(sizeof(ProcessInfo) * (createNumChildren + 1));

  pid_t fork_pid, my_pid;
  int x;
  int i;

  processInfo[0].processId = getpid();
  gettimeofday(processInfo[0].startTime, NULL);

  for(i = 1; i < createNumChildren+1; i++){
    gettimeofday(processInfo[i].startTime, NULL);
    fork_pid = fork();   /* Create a child process */
    if (fork_pid<0) {    /* Check forked correctly */
      fprintf(stderr, "Fork failed\n");
      exit(2);
    }
    my_pid = getpid();

    if (fork_pid==0) { /* If the current process is the child process.*/
      printf("I am the child process.  fork_pid = %d, my_pid = %d\n", 
             fork_pid, my_pid);

      // Set index
      index = i;
      processInfo[index].processId = getpid();
      
      usleep((createNumChildren-index)*delayMicroseconds);
      printf("%d\n", index);

      char buffer[513];
      int line = 0;
      int length = -1;
      FILE *inFile = NULL;

      inFile = fopen(fileName, "r");
      if (inFile == NULL) {
        printf("Failed to open input file\n");
        exit(-2);
      }
      while (line <= index) {
        length = ReadLineFromFile(inFile, buffer);
        if(length == -1){
          rewind(inFile);
          continue;
        }
        line++;
      }
      fclose(inFile);
        char* outputName = malloc(strlen(buffer) + 4);
      strncpy(outputName, buffer, strlen(buffer)-5);
      char* ending = "_out.txt";
      // strncpy(outputName + strlen(buffer)-4, ending, strlen(ending));
      strcat(outputName, ending);

      printf("*%s*\n", outputName);

      // execl("./myCopy", buffer, outputName);


      break;
    }
    else { /* If the current   process is the parent process. */
      printf("I am the parent process.  fork_pid = %d, my_pid = %d\n", 
             fork_pid, my_pid);
    }
  }

  

  /* Adding some random delay to make the process run a little longer. */
  srand(my_pid);
  for (x=0; x<10000; x++) {
    if (rand()%2==0) {
      sleep( 0.01 );
    }
  }

  printf("Now exiting -- pid %d over and out.\n", my_pid);

  return 0;
}


int ReadLineFromFile(FILE* file, char* buffer) {
  if (fgets(buffer, 513, file) != NULL) {
    return strlen(buffer);
  }
  return -1;
}
