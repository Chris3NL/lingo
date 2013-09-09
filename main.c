#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehandler.h"
#include "lingo.h"

int main()
{
    char input[MAX_LINES];
    char strReturn[MAX_LINES];
    srand(time(NULL));

    if(GetFileData("woorden.txt") != 1)
    {
        return 0;
    }
    initGame();

//    geefNieuw();
//    geefNieuw();
//    geefNieuw();

    while(iHuidigGame < AANTAL_GAMES)
    {
        //heeft nog spellen
        geefNieuw();
        printf("SPEL: %i\n", iHuidigGame);
        printf("---------------------------------------\n");

        while(iHuidigePoging < POGINGEN)
        {
            //heeft nog pogingen

            memset(strReturn,0,MAX_WOORD); //leeg buffer

            printf("Poging: %i\n", iHuidigePoging+1);
            iHuidigePoging++;
            printf("%s\n", strBordWoord);
            printf("---------------------------------------\n");
            scanf("%s", &input);

            checkWoord(input, &strReturn);

            printf("out: %s\n", strReturn);


//            printf("in:%i: %s\n", strlen(input), input);
        }
        if(iHuidigePoging == POGINGEN)
        {
            printf("Het woord was: %s\n", strHuidigWoord);
        }
        printf("---------------------------------------\n");
        printf("Nog een spel spelen? [j/n]: ");
        scanf("%s", &input);
        if(input[0] != 'y' && input[0] != 'j' && input[0] != 'J' && input[0] != 'Y')
        {
            break;
        }
    }//*/



    printf("Hello world!\n");
    return 0;
}
