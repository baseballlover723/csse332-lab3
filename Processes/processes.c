/* This is where you implement the core solution.
   by <Name>, <Date>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

  if(arc != 4){
    printf("%s\n", "Unexpected number of arguments");
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

  for(i = 0; i < numChildrenCreated; i++){
    fork_pid = fork();   /* Create a child process */
    if (fork_pid<0) {    /* Check forked correctly */
      fprintf(stderr, "Fork failed\n");
      exit(2);
    }
    if (fork_pid==0) { /* If the current process is the child process.*/
      printf("I am the child process.  fork_pid = %d, my_pid = %d\n", 
             fork_pid, my_pid);

      // Set index
      index = i;
      processInfo[index].processId = getpid();
      gettimeofday(processInfo[index].startTime, NULL);
      break;
    }
    else { /* If the current   process is the parent process. */
      printf("I am the parent process.  fork_pid = %d, my_pid = %d\n", 
             fork_pid, my_pid);
      
    }
  }

  my_pid = getpid();

  

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
