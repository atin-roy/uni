#include <stdio.h>

int main() {
  FILE *sourceFile, *destinationFile;
  char sourceFileName[100], destinationFileName[100];
  char ch;

  printf("Enter the name of source file: ");
  scanf("%s", sourceFileName);

  sourceFile = fopen(sourceFileName, "r");

  if (sourceFile == NULL) {
    printf("Error: Unable to open source file.\n");
    return 1;
  }

  printf("Enter the name of destination file: ");
  scanf("%s", destinationFileName);

  destinationFile = fopen(destinationFileName, "w");

  if (destinationFile == NULL) {
    printf("Error: Unable to create or open destination file.\n");
    fclose(sourceFile);
    return 1;
  }

  while ((ch = fgetc(sourceFile)) != EOF) {
    fputc(ch, destinationFile);
  }

  printf("File copied successfully.\n");

  fclose(sourceFile);
  fclose(destinationFile);

  return 0;
}
