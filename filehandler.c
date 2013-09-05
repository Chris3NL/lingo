#include "filehandler.h"

int OpenFile(char *strFilename)
{
    pFile = fopen(strFilename,"r");
    return 0;
}
