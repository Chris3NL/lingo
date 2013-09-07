#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

FILE *pFile;
int iFileLines;
char strFileData[MAX_LINES][16];

int OpenFile(char *strFilename);
void CloseFile();
int GetFileData(char *strFilename);
