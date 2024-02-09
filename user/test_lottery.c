#include "kernel/pstat.h"
#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int 
main() {
  struct pstat p;
  
  if (fork() == 0) {
    char* args[] = {"exist","10"};
    exec("/exist", args);
  }
  if (fork() == 0) {
    char* args[] = {"exist","20"};
    exec("/exist", args);
  }
  if (fork() == 0) {
    char* args[] = {"exist","30"};
    exec("/exist", args);
  }
  

  while (1) {
    getpinfo(&p);
    for (int i = 0; i < NPROC; i++) 
      if (p.inuse[i])
        printf("%d %d %d\n", p.pid[i], p.tickets[i], p.ticks[i]);
  }

  return 0;
}
