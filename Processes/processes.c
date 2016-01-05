/* This is where you implement the core solution.
   by <Name>, <Date>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
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

  pid_t fork_pid;
  int i;

  processInfo[0].processId = getpid();
  struct timeval *processStartTime = (struct timeval*) malloc(sizeof(struct timeval));
  struct timeval *processEndTime = NULL;
  gettimeofday(processStartTime, NULL);
  processInfo[0].startTime = processStartTime;

  for(i = 1; i < createNumChildren+1; i++){
    processStartTime = (struct timeval*) malloc(sizeof(struct timeval));
    gettimeofday(processStartTime, NULL);
    processInfo[i].startTime = processStartTime;

    fork_pid = fork();   /* Create a child process */
    if (fork_pid<0) {    /* Check forked correctly */
      fprintf(stderr, "Fork failed\n");
      exit(2);
    }

    if (fork_pid==0) { /* If the current process is the child process.*/

      // Set index
      index = i;
      
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

      buffer[strlen(buffer)-1] = '\0';
      char* outputName = malloc(strlen(buffer) + 4);
      strncpy(outputName, buffer, strlen(buffer)-4);
      char* ending = "_out.txt";
      // strncpy(outputName + strlen(buffer)-4, ending, strlen(ending));
      strcat(outputName, ending);

      execl("./myCopy", "./myCopy", buffer, outputName, NULL);

      exit(-1);
    }
    else { /* If the current   process is the parent process. */
      processInfo[i].processId = fork_pid;
    }
  }
  
  pid_t wpid;
  int status;
  while ((wpid = wait(&status)) > 0){
    int i;
    for(i = 0; i < createNumChildren+1; i++){

      if(wpid == processInfo[i].processId){
        processEndTime = (struct timeval*) malloc(sizeof(struct timeval));
        gettimeofday(processEndTime, NULL);
        processInfo[i].endTime = processEndTime;
        long elapsed = (processInfo[i].endTime->tv_sec-processInfo[i].startTime->tv_sec)*1000000 + processInfo[i].endTime->tv_usec-processInfo[i].startTime->tv_usec;
        printf("Time for process %d = %ld microseconds\n", i, elapsed);
        break;
      }
    }
  }

  processEndTime = (struct timeval*) malloc(sizeof(struct timeval));
  gettimeofday(processEndTime, NULL);
  processInfo[0].endTime = processEndTime;
  long elapsed = (processInfo[0].endTime->tv_sec-processInfo[0].startTime->tv_sec)*1000000 + processInfo[0].endTime->tv_usec-processInfo[0].startTime->tv_usec;
  printf("All children have finished, parent process now exiting. Execution time: %ld \n", elapsed);

  return 0;
}

int64_t timevaldiff(struct timeval starttime, struct timeval finishtime)
{
  int64_t usec;
  usec=(finishtime.tv_sec-starttime.tv_sec)*1000000;
  usec+=(finishtime.tv_usec-starttime.tv_usec);
  return usec;
}

int ReadLineFromFile(FILE* file, char* buffer) {
  if (fgets(buffer, 513, file) != NULL) {
    return strlen(buffer);
  }
  return -1;
}
