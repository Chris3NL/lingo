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
    printf("Juiste letter juiste plek: #\n");
    printf("Juiste letter verkeerde plek: ^\n");
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
        for(i=0; i<=AANTAL_GAMES; i++)
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
    printf("HUIDIG: %s\n",strHuidigWoord);

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

void checkWoord(char *input, char *output)
{

    char strRestLTRS[MAX_WOORD];

    int i, j;

    strcpy(strRestLTRS, strBordWoord);

    //Kijken voor goede plek goede letter
    for(i=0; i<iWoordLengte; i++)
    {
        printf("%i: %c::%i\n",i, input[i], input[i]);
        if(input[i] == strHuidigWoord[i])
        {
            //goed/goed
            output[i] = '#';
            strRestLTRS[i] = '.';
        }
    }

    //kijken voor goede letter verkeerde plek
    for(i=0; i<WoordLengte; i++)
    {
        //for voor input
        for(j=0; j<WoordLengte; j++)
        {
            //for voor controle
            if(intput[i] == strRestLTRS[j] && strRestLTRS[j] != '.')
            {

            }
        }
    }
}
