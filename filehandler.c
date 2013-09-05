#include "filehandler.h"

int OpenFile(char *strFilename)
{
    pFile = fopen(strFilename,"r");
    if(pFile!=NULL)
    {
        return -1;
    }
    return 0;
}

void CloseFile()
{
    fclose(pFile);
}

int GetFilelines()
{
    if(pFile == NULL)
    {
        return -1;
    }
    
    return 0;
}