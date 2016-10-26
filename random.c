#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int myrand(){
  int f = open("/dev/random",O_RDONLY);
  void * p = malloc(4);
  read(f,p,4);
  printf("%d\n",*((int*)p));
  srand(*((int*)p));
  free(p);
  return rand();
}

int main(){
  int arr[10];
  int c = 0;
  printf("Generating Numbers:\n");
  while (c<10){
    int n = myrand();
    arr[c] = n;
    printf("random#%d - %d",c+1,n );
    c++;
  }
  printf("\n");
  return 0;
}
