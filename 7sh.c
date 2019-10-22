#include "sys/wait.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
int main(int argc, char const *argv[])
{
  int p2c[2],c2p[2];
  pid_t cpid;
  char bufp2c[200],bufc2p[200],fnm[200],str[1000];
  FILE *fp,*fp1;
  cpid=fork();
  if(cpid==0)
  {
    close(p2c[1]);
    read(p2c[0],bufp2c,20);
    close(p2c[0]);
    fp=fopen(bufp2c,"r");
    printf("\n###############child####################");
    while (fscanf(fp,"%s",str)!=EOF)
     {
       write(1,&str,strlen(str)+1);
    }
    fclose(fp);
    close(c2p[0]);
    write(c2p[1],str,1000);
    close(c2p[1]);
    exit(0);

  }
  else
  {
      printf("\nenter file name:");
      scanf("%s",fnm);
      close(p2c[0]);
      write(p2c[1],fnm,15);
      close(p2c[1]);
      sleep(5);
      printf("\n###########parent########");
      close(c2p[1]);
      read(c2p[0],bufc2p,1000);
      close(c2p[1]);
      write(1,&bufc2p,strlen(bufc2p)+1);
      printf("\n\n");
      exit(0);
  }
  return 0;
}
