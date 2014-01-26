#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehandler.h"
#include "lingo.h"

/** \brief Main function
 *
 * \param int argc arguments counter (notused)
 * \param char *argv[] arguments array (notused)
 * \return int systeem return (always 0)
 *
 */
int main(int argc, char *argv[])
{
    char input[MAX_LINES]; /**< variable for user input*/
    char strReturn[MAX_LINES]; /**< variable for symbolic return */

    srand(time(NULL)); // seed the rand function

    // Open te file and read it into memory
    if(GetFileData("woorden.txt") != 1)
    {
        return 1; //FAIL
    }

    initGame(); //Init game

    while(iHuidigGame < AANTAL_GAMES)
    {
        //Still has games
        geefNieuw(); //give new game
        printf("SPEL: %i\n", iHuidigGame);
        printf("---------------------------------------\n");
        printf("Juiste letter juiste plek: #\n");
        printf("Juiste letter verkeerde plek: ^\n");
        printf("---------------------------------------\n");

        while(iHuidigePoging < POGINGEN)
        {
            //Still has tries left

            memset(strReturn,0,MAX_WOORD); //Empty buffer

            printf("Poging: %i\n", iHuidigePoging+1);
            iHuidigePoging++;
            printf("%s\n", strBordWoord);
            printf("---------------------------------------\n");
            scanf("%s", &input);

            //Checking user input
            if(checkWoord(input, &strBordWoord, &strReturn) == 33)
            {
                printf("GEWONNEN\n");
                iHuidigePoging = 33;
                break;
            }

            printf("%s\n", strReturn);


//            printf("in:%i: %s\n", strlen(input), input);
        }
        if(iHuidigePoging == POGINGEN)
        {
            //Failed to gues the word
            printf("Het woord was: %s\n", strHuidigWoord);
        }
        if(iHuidigGame != AANTAL_GAMES)
        {
            //If not last game ask for an other
            printf("---------------------------------------\n");
            printf("Nog een spel spelen? [j/n]: ");
            scanf("%s", &input);
            if(input[0] != 'y' && input[0] != 'j' && input[0] != 'J' && input[0] != 'Y')
            {
                //If the answer is not j J y Y then kill the program
                break;
            }
        }

    }

    printf("Bedankt voor het spelen van LINGO\n");
    return 0;
}
