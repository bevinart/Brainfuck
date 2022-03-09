#include <brainfuck.h>

void read(struct Brainfuck process, char * bfCode) {
    process.CELL_PTR = 0;
    process.CELLS = (int*)malloc(getCellCount(bfCode)+1);

    int loopPos;

    // Makes the number only 1
    int highestCellNum=0;
    process.CELLS[process.CELL_PTR] = 0;
    
    for (int i = 0; i < strlen(bfCode); i++) {
        int procCell = process.CELLS[process.CELL_PTR];
        
        // Switch case won't work so I have to do if-else statements
        if (bfCode[i]=='+') {
            if (procCell >= 255) {
                process.CELLS[process.CELL_PTR]=0;
            }
            else {
                process.CELLS[process.CELL_PTR]++;
            }
        }
        else if(bfCode[i]=='-') {
            if (procCell <= 0) {
                process.CELLS[process.CELL_PTR]=255;
            }
            else {
                process.CELLS[process.CELL_PTR]--;
            }
        }
        else if (bfCode[i]=='.') {
            printf("%i", process.CELLS[process.CELL_PTR]);
        }

        else if (bfCode[i]=='>') {
            process.CELL_PTR++;
            if (process.CELL_PTR > highestCellNum) {
                process.CELLS[process.CELL_PTR] = 0;
                highestCellNum = process.CELL_PTR;
            }
        }
        else if (bfCode[i]=='<') {
            if (process.CELL_PTR <= 0) {
                //Throw Err
            }
            process.CELL_PTR--;
        }
        else if (bfCode[i]==']') {
            if (procCell==0) {
                continue;
            }
            else {
                process.CELL_PTR = loopPos;
            }
        }
        else if (bfCode[i]=='[') {
            loopPos = i+1;
        }

        continue;
    }
}

int getCellCount(char * bfCode) {
    int highestCellCount=0;
    int cellCount=0;
    
    for (int i = 0; i < (strlen(bfCode)); i++) {
        if (bfCode[i] == '>') {
            cellCount++;
            if (cellCount > highestCellCount) {
                    highestCellCount = cellCount;
            }
        }
        else if (bfCode[i] == '<') {
            cellCount--;
        }
        continue;
    }

    return highestCellCount;
}

int getCharCount(char * str, char substr) {
    int charCount=0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]==substr) {
            charCount++;
        }
    }
    return charCount;
}