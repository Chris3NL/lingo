#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define AANTAL_GAMES 10
#define POGINGEN 5
#define MAX_WOORD 16

int iUsedLines[AANTAL_GAMES];
int iHuidigGame;
int iGameStarted;
int iHuidigWoord;
int iHuidigePoging;
int iFail;
char strHuidigWoord[MAX_WOORD];
char strBordWoord[MAX_WOORD];

void initGame();
void geefNieuw(); //Geef een nieuw woord
int checkWoord(char *input, char *output, char *output2); //Controleer de input van de user met het woord
