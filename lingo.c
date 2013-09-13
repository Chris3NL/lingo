#include "lingo.h"

int iWoordLengte; /**< Current word length */

/** \brief reset global variables
 *
 * \param void
 * \return void
 *
 */
void initGame()
{
    int i;
    //reset all games
    for(i=0; i<=AANTAL_GAMES; i++)
    {
        iUsedLines[i] = -1;
    }
    iHuidigGame = 0;
    iHuidigWoord = -1;
    iHuidigePoging = 0;
    strcpy(strHuidigWoord, "");
    strcpy(strBordWoord, "");

    printf("WELKOM BIJ LINGO\n");
    printf("---------------------------------------\n");


}

/** \brief Give a new word
 *
 * \param void
 * \return void
 *
 */
void geefNieuw()
{
    int irand;
    int igeweest = 1;
    int i;
    int itemp;
//    char strTemp[16];

    while(igeweest == 1)
    {
        //while the word is already been or hasn't run once the give new word
        irand = rand()%(iFileLines+1);
        for(i=0; i<AANTAL_GAMES; i++)
        {
            if(irand != iUsedLines[i])
            {
                //it hasn't already been on the screen
                igeweest = 0;
            }
        }
    }

    //We have had him now
    iUsedLines[iHuidigGame] = irand;

//    strcpy(strTemp, strBordWoord[i])

    itemp = strlen( strFileData[irand] );
//    printf("i1: %i\n",itemp);
    //Put it in current word
    strncpy(strHuidigWoord,strFileData[irand], itemp-1);
//    printf("HUIDIG: %s\n",strHuidigWoord);

    //Make a word with only the first character and dots
    memset(strBordWoord,0,MAX_WOORD);
 //   printf("BW: %s:%c\n", strBordWoord, strBordWoord[4]);
    strncpy(strBordWoord,strHuidigWoord,1);
    iWoordLengte = strlen(strHuidigWoord);
//    printf("i2: %i\n",iWoordLengte);

    for(i=1; i<iWoordLengte; i++)
    {
//        printf("i: %i\n",i);
        strcat(strBordWoord,".");
    }
//    printf("SCHERM: %s\n",strBordWoord);
    iHuidigePoging = 0;
    iHuidigGame++;
}

/** \brief checking the input to the current word
 *
 * \param char *input user input from the screen
 * \param char *output output to the screen (also know as strBordWoord)
 * \param char *output2 a symbolic respentation of the avaiable letters
 * \return char *output and *output2
 * \return int errorcode (33=GOOD/GOOD, 1=NOFAIL, 0=FAIL)
 *
 */
int checkWoord(char *input, char *output, char *output2)
{

    char strRestLTRS[MAX_WOORD];
//    char output2[MAX_WOORD];
    int iFail = 0;
    int i, j, k;

    //Put current word in temp string
    strcpy(strRestLTRS, strHuidigWoord);

    //Look for good place and good character
    for(i=0; i<iWoordLengte; i++)
    {
 //       printf("%i: %c::%i\n",i, input[i], input[i]);
        if(input[i] == strHuidigWoord[i])
        {
            //good/good
            output[i] = strHuidigWoord[i];
            output2[i] = '#';
            strRestLTRS[i] = '.';
            input[i] = '.';
        }
        else
        {
            if(output[i] == 0)
            {
                output[i] = '.';
            }
            iFail = 1;
        }
    }

    if(iFail == 0)
    {
        //we have all the character good/good
        return 33;
    }

//    printf("REST: %s\n", strRestLTRS);
//    printf("OUT: %s\n", output);

    //Look for good character wrong spot
    for(i=0, k=0; i<iWoordLengte; i++)
    {
        //for for input
        for(j=0; j<iWoordLengte; j++)
        {
            //for for check
            if(input[i] == strRestLTRS[j] && strRestLTRS[j] != '.')
            {
                //good but wrong spot
                output2[i] = '^';
                strRestLTRS[j] = '.';
                k++;
                break;
            }
            else
            {
                if(output2[i] != '#')
                {
                    output2[i] = '.';
                }
            }
 //           printf("%c",output2[i]);
        }
    }
//    printf("\n");
    return 1;
}
