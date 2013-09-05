#include <stdio.h>
#include <stdlib.h>

FILE *pFile;

int OpenFile(char *strFilename);
void CloseFile();
int GetFilelines(FILE pFilePointer);
