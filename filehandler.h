#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 /**< Maximal filelines to read */

FILE *pFile; /**< FILE pointer for the filehandler */
int iFileLines; /**< File line counter */
char strFileData[MAX_LINES][16]; /**< Filedata array */

/** \brief Opening specified file
 *
 * \param char *strFilename The location/name of the file to open
 * \return int errorcode (1=success, 0=fail)
 *
 */
int OpenFile(char *strFilename);

/** \brief Closing the file
 *
 * \param void
 * \return void
 *
 */
void CloseFile(void);

/** \brief Get filedata in an array
 *
 * \param char *strFilename The location/name of the file to open and read from
 * \return int errorcode (1=success, 0=fail)
 *
 */
int GetFileData(char *strFilename);
