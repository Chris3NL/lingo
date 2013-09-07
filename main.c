#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehandler.h"
#include "lingo.h"

int main()
{

    srand(time(NULL));

    if(GetFileData("woorden.txt") != 1)
    {
        return 0;
    }
    initGame();

    geefNieuw();
    geefNieuw();
    geefNieuw();
/*
    while(iHuidigGame < AANTAL_GAMES)
    {
        //heeft nog spellen
        geefNieuw();
        printf("SPEL: %i\n", iHuidigGame);

        while(iHuidigePoging < POGINGEN)
        {
            //heeft nog pogingen
            printf("Poging: %i\n", iHuidigePoging+1);
            iHuidigePoging++;
        }
    }//*/



    printf("Hello world!\n");
    return 0;
}
