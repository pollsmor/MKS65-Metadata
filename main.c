#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("Printing out metadata of main.c: \n");
  struct stat metadata;
  stat("main.c", &metadata);

  printf("File size: \n");
  char buffer[50];
  printf("> %ld B \n", metadata.st_size);
  sprintf(buffer, "> %f KB \n", metadata.st_size / 1000.0);
  if (metadata.st_size > 1000000) //larger than 1 MB
    sprintf(buffer, "> %f MB \n", metadata.st_size / 1000000.0);
  if (metadata.st_size > 1000000000) //larger than 1 GB
    sprintf(buffer, "> %f GB \n", metadata.st_size / 1000000000.0);
  printf("%s \n", buffer);

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
