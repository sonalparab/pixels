#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256 * 2
#define STR_SIZE 18

void generateimage(){
  int f = open("image.ppm",O_CREAT|O_WRONLY,0666);

  char * s = (char *) calloc(STR_SIZE,sizeof(char));
  sprintf(s,"P3 %d %d %d\n",SIZE,SIZE,255);
  write(f,s,STR_SIZE);

  free(s);
  
  int i;
  int j;
  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE; j++){
      int r = (SIZE - j) % 256;
      int g = i % 256;
      int b = j % 256;
      char * p = (char *) calloc(STR_SIZE,sizeof(char));
      sprintf(p,"%d %d %d \n",r,g,b);
      write(f,p,STR_SIZE);
      free(p);
    }
  }

  close(f);
  
}

int main(){

  generateimage();

  return 0;
}
