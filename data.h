#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_LENGTH 81
#define CMD_NUM 16


/* variable helpers */
extern int IC;
extern int DC;


/* command definitions */
typedef struct Command {
    const char * cmdName;
    int opCode;
    int numOfOps;

} Command;

extern Command commandTable[CMD_NUM];


/* word definition */
typedef struct Word {
    unsigned int ARE:2;
    unsigned int desO:2;
    unsigned int srcO:2;
    unsigned int opcode:4;
    unsigned int na:4;
} Word;


/* symbol definition */
typedef struct Symbol{
    const char * symbolName;
    unsigned int value;
};

/* functions */

void initData();

#endif