#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define AANTAL_GAMES 5
#define POGINGEN 3;

int iUsedLines[AANTAL_GAMES];
int iHuidigGame;
int iGameStarted;
int iHuidigWoord;
int iHuidigePoging;
char strHuidigWoord[16];
char strBordWoord[16];

void initGame();
int checkWoord(char *input);
int heeftPoging();
void geefWoord();
void geefNieuw();
