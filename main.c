#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("Printing out metadata of main.c: \n");
  struct stat metadata;
  stat("main.c", &metadata);
  printf("File size: \n");
  printf("> %ld B \n", metadata.st_size);
  printf("> %lf KB \n", metadata.st_size / 1000.0);
  printf("> %lf MB \n", metadata.st_size / 1000000.0);
  if (metadata.st_size > 1000000) //larger than 1MB
    printf("> %lf GB \n", metadata.st_size / 1000000000.0);
  printf("\n");

  printf("Last accessed: \n");
  printf("> %s \n", ctime(&metadata.st_atime));

  printf("Raw file permissions: %d \n", metadata.st_mode);

  printf("ls -l permissions format for main.c: \n");
  printf("> ");
  printf( (metadata.st_mode & S_IRUSR) ? "r" : "-");
  printf( (metadata.st_mode & S_IWUSR) ? "w" : "-");
  printf( (metadata.st_mode & S_IXUSR) ? "x" : "-");
  printf( (metadata.st_mode & S_IRGRP) ? "r" : "-");
  printf( (metadata.st_mode & S_IWGRP) ? "w" : "-");
  printf( (metadata.st_mode & S_IXGRP) ? "x" : "-");
  printf( (metadata.st_mode & S_IROTH) ? "r" : "-");
  printf( (metadata.st_mode & S_IWOTH) ? "w" : "-");
  printf( (metadata.st_mode & S_IXUSR) ? "x" : "-");

  printf("\n");

  return 0;
}
