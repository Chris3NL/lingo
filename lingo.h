#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define AANTAL_GAMES 10 /**< Max games can be run */
#define POGINGEN 5 /**< Max tries */
#define MAX_WOORD 16 /**< Max word length */

int iUsedLines[AANTAL_GAMES]; /**< Used fileline so don't give word twice */
int iHuidigGame; /**< curent game */
int iHuidigWoord; /**< current word number */
int iHuidigePoging; /**< current try */
char strHuidigWoord[MAX_WOORD]; /**< current word */
char strBordWoord[MAX_WOORD]; /**< current word on the screen */

/** \brief reset global variables
 *
 * \param void
 * \return void
 *
 */
void initGame(void);

/** \brief Give a new word
 *
 * \param void
 * \return void
 *
 */
void geefNieuw(void);

/** \brief checking the input to the current word
 *
 * \param char *input user input from the screen
 * \param char *output output to the screen (also know as strBordWoord)
 * \param char *output2 a symbolic respentation of the avaiable letters
 * \return char *output and *output2
 * \return int errorcode (33=GOOD/GOOD, 1=NOFAIL, 0=FAIL)
 *
 */
int checkWoord(char *input, char *output, char *output2);
