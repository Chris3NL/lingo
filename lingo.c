#include "lingo.h"

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

}

void geefNieuw()
{
    int irand;
    int igeweest = 1;
    int i;
    int itemp;

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

    //Zet hem in het huidige woord
    strcpy(strHuidigWoord,strFileData[irand]);
    printf("HUIDIG: %s\n",strHuidigWoord);

    //Maak een woord met de eerste letter en puntjes
    strncpy(strBordWoord,strHuidigWoord,1);
    itemp = strlen(strHuidigWoord);
    for(i=0; i<itemp; i++)
    {
        strcat(strHuidigWoord,".");
    }
}
