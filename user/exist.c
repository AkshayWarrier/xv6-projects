#include "kernel/types.h"
#include "user/user.h"

// Run this to make a process run indefinetly
int 
main(int argc, char** argv) {
  int t = atoi(argv[1]);
  settickets(t);
  while(1){}
  return 0;
}
