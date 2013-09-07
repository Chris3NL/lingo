#include "filehandler.h"


int OpenFile(char *strFilename)
{
    pFile = fopen(strFilename,"r");
    if(pFile != NULL)
    {
        return 1;
    }
    return 0;
}

void CloseFile()
{
    fclose(pFile);
}


int GetFileData(char *strFilename)
{
    char strTemp[16];
    int i=0;

    if(OpenFile(strFilename) != 1)
    {
        printf("Kan %s niet openen!\n", strFilename);
        return 0;
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

    if(iFileLines < 10)
    {
        printf("Minder dan 10 woorden in de lijst!\n");
        return 0;
    }

    return 1;
}
//*/
