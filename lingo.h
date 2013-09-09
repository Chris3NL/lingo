#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define AANTAL_GAMES 5
#define POGINGEN 3

int iUsedLines[AANTAL_GAMES];
int iHuidigGame;
int iGameStarted;
int iHuidigWoord;
int iHuidigePoging;
int iFail;
char strHuidigWoord[16];
char strBordWoord[16];

void initGame();
int checkWoord(char *input); //Controleer de input van de user met het woord
int heeftPoging();
void geefWoord(); //Geef het volledige woord
void geefNieuw(); //Geef een nieuw woord
