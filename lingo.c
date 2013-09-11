#include "lingo.h"

int iWoordLengte;

void initGame()
{
    int i;
    for(i=0; i<=AANTAL_GAMES; i++)
    {
        iUsedLines[i] = -1;
    }
    iHuidigGame = 0;
    iGameStarted = 0;
    iHuidigWoord = -1;
    iHuidigePoging = 0;
    strcpy(strHuidigWoord, "");
    strcpy(strBordWoord, "");

    printf("WELKOM BIJ LINGO\n");
    printf("---------------------------------------\n");


}

void geefNieuw()
{
    int irand;
    int igeweest = 1;
    int i;
    int itemp;
//    char strTemp[16];

    while(igeweest == 1)
    {
        irand = rand()%(iFileLines+1);
        for(i=0; i<AANTAL_GAMES; i++)
        {
            if(irand != iUsedLines[i])
            {
                igeweest = 0;
            }
        }
    }
    //We hebben hem nu gehad
    iUsedLines[iHuidigGame] = irand;

//    strcpy(strTemp, strBordWoord[i])

    itemp = strlen( strFileData[irand] );
//    printf("i1: %i\n",itemp);
    //Zet hem in het huidige woord
    strncpy(strHuidigWoord,strFileData[irand], itemp-1);
//    printf("HUIDIG: %s\n",strHuidigWoord);

    //Maak een woord met de eerste letter en puntjes
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
    iFail = 0;
}

int checkWoord(char *input, char *output, char *output2)
{

    char strRestLTRS[MAX_WOORD];
//    char output2[MAX_WOORD];
    int iFail = 0;
    int i, j, k;

    strcpy(strRestLTRS, strHuidigWoord);

    //Kijken voor goede plek goede letter
    for(i=0; i<iWoordLengte; i++)
    {
 //       printf("%i: %c::%i\n",i, input[i], input[i]);
        if(input[i] == strHuidigWoord[i])
        {
            //goed/goed
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
        return 33;
    }

//    printf("REST: %s\n", strRestLTRS);
//    printf("OUT: %s\n", output);

    //kijken voor goede letter verkeerde plek
    for(i=0, k=0; i<iWoordLengte; i++)
    {
        //for voor input
        for(j=0; j<iWoordLengte; j++)
        {
            //for voor controle
            if(input[i] == strRestLTRS[j] && strRestLTRS[j] != '.')
            {
                output2[i] = '^';//input[i];
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
    return 0;
}
