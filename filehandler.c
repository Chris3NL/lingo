#include "filehandler.h"
#include "lingo.h"


/** \brief Opening specified file
 *
 * \param char *strFilename The location/name of the file to open
 * \return int errorcode (1=success, 0=fail)
 *
 */
int OpenFile(char *strFilename)
{
    pFile = fopen(strFilename,"r"); //Open file
    if(pFile != NULL)
    {
        //If succes return 1
        return 1;
    }
    //Else return 0
    return 0;
}

/** \brief Closing the file
 *
 * \param void
 * \return void
 *
 */
void CloseFile(void)
{
    //Just close the file
    fclose(pFile);
}

/** \brief Get filedata in an array
 *
 * \param char *strFilename The location/name of the file to open and read from
 * \return int errorcode (1=success, 0=fail)
 *
 */
int GetFileData(char *strFilename)
{
    char strTemp[16]; /**< Tempary string for reading data */

    if(OpenFile(strFilename) != 1)
    {
        //Can't open File
        printf("Kan %s niet openen!\n", strFilename);
        return 0;
    }
    printf("%s geopend\n", strFilename);

    iFileLines = 0;

    while((fgets (strTemp , MAX_WOORD+1 , pFile) != NULL) && (iFileLines < (MAX_LINES))) //MAX_WOORD+1 for the \n
    {
//        printf("Line: %i=> %s",i,strTemp);
//        printf("regel: %i\n",i);
        strcpy(strFileData[iFileLines],strTemp); //copy in next word
        iFileLines++;
    }

    CloseFile(); //Close file

    if(iFileLines < 10)
    {
        //Less the 10 lines in the file
        printf("Minder dan 10 woorden in de lijst!\n");
        return 0;
    }

    return 1; //success
}
//*/
