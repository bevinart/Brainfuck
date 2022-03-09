#ifndef BRAINFUCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Brainfuck {
    // User set arguments
    int isSilentPrint;
    
    int * CELLS;
    int CELL_PTR;
};

void read(struct Brainfuck process, char * bfCode);
int getCellCount(char * bfCode);
int getCharCount(char * str, char substr);

#define BRAINFUCK_H
#endif