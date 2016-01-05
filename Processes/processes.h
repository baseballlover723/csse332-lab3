/* Use this header file to include function signatures and to declare structure types.
   by <Name>, <Date>
*/

#include <sys/time.h>

typedef struct ProcessInfo {
  int processId;
  struct timeval* startTime;
  struct timeval* endTime;
} ProcessInfo;

int ReadLineFromFile(FILE* file, char* buffer);
int64_t timevaldiff(struct timeval starttime, struct timeval finishtime);

