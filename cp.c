/**cp.c
version 1
**/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 4096
#define COPYMODE 0644

void oops(char *,char *);

int main(int ac,char *av[])
{
  int int_fd,out_fd,n_chars;
  char buf[BUFFSIZE];
  if (ac != 3){
    fprintf(stderr,"usage:%ssourse destination\n",*av);
    exit(1);
  }
  if ((int_fd = open(av[1],O_RDONLY)) == -1)
    oops("Cannot open!",av[1]);
  if ((out_fd = creat(av[2], COPYMODE)) == -1)
    oops("Cannot creat",av[2]);
  while ((n_chars = read(int_fd,buf,BUFFSIZE)) > 0){
    if ((write(out_fd,buf,BUFFSIZE)) != n_chars)
      oops("Write error to",av[2]);
    }
  if ( close(int_fd) == -1 || close(out_fd) == -1)
    oops("Error closing files","");
  return 0;
  }

void oops(char *s1,char *s2)
{
  fprintf(stderr,"Error:%s",s1);
  perror(s2);
  exit(1);
}
