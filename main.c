#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() 
{
  FILE *ogdir = fopen("original_directory.txt", "a");

  struct dirent *de;
  DIR *dir = opendir(".");

  if (dir == NULL) {
    printf("Could not open directory\n");
    return 1;
  }

  char *files[100];
  int i =0;
  while ((de = readdir(dir)) != NULL) {
    if (de->d_name[0] == '.' || strcmp(de->d_name, "original_directory.txt") == 0)
      continue;

    files[i++] = de->d_name;

    fprintf(ogdir, "%s", de->d_name); 
  }

  closedir(dir);
  fclose(ogdir);

  remove("original_directory.txt");
  system("ls | vim -c 'saveas new_directory.txt' -");

  FILE *newdir = fopen("new_directory.txt", "r");
  char newbuf[100];

  i = 0;
  while(fgets(newbuf, 100, newdir)) {
    if (strncmp(files[i], newbuf, 100) != 0) {  
      char cmd[255];
      sprintf(cmd, "mv %s %s", files[i++], newbuf);
      system(cmd);
    }
  }

  fclose(newdir);
  remove("new_directory.txt");

  return 0;
}


