#include "kernel/pstat.h"
#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  struct pstat p;
  getpinfo(&p);
  for (int i = 0; i < NPROC; i++) 
    printf("%d %d %d\n", p.inuse[i], p.tickets[i], p.pid[i]);
  return 0;
}

