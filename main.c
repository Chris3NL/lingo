#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehandler.h"
#include "lingo.h"

int main()
{

    srand(time(NULL));

    GetFileData("woorden.txt");
    initGame();




    printf("Hello world!\n");
    return 0;
}
