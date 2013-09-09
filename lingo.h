#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define AANTAL_GAMES 5
#define POGINGEN 3
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
void checkWoord(char *input, char *output); //Controleer de input van de user met het woord
