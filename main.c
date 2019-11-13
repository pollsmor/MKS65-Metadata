#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("Printing out metadata of main.c: \n");
  struct stat metadata;
  stat("main.c", &metadata);
  printf("File size: %ld \n", metadata.st_size);
  printf("File permissions: %d \n", metadata.st_mode);
  printf("Last accessed: %ld \n", metadata.st_atime);

  return 0;
}
