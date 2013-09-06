#include "filehandler.h"


int OpenFile(char *strFilename)
{
    pFile = fopen(strFilename,"r");
    if(pFile != NULL)
    {
        return 0;
    }
    return -1;
}

void CloseFile()
{
    fclose(pFile);
}


void GetFileData(char *strFilename)
{
    char strTemp[16];
    int i=0;

    if(OpenFile(strFilename) != 0)
    {
        printf("Kan %s niet openen!\n", strFilename);
        return;
    }
    printf("%s geopend\n", strFilename);

    while((fgets (strTemp , 16 , pFile) != NULL) && (i < (MAX_LINES)))
    {
//        printf("Line: %i=> %s",i,strTemp);
//        printf("regel: %i\n",i);
        strcpy(strFileData[i],strTemp);
        i++;
    }

    iFileLines = i;
    CloseFile();
}
//*/
