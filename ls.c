//ls.c
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls(char[]);

int main (int ac, char *av[])
{
  if (ac==1)
    do_ls(".");
  else
    while(--ac){
      printf("%s",*++av);
      do_ls(*av);
    }
  return 0;
}

void do_ls(char dirname[])
{
  DIR *dir_ptr;
  struct dirent *direntp;

  if((dir_ptr=opendir(dirname))==0)
    fprintf(stderr,"ls Cannot open%s\n",dirname);
  else{
    while((direntp=readdir(dir_ptr))!=0)
      printf("%s\n",direntp->d_name);
    closedir(dir_ptr);
  }
}
