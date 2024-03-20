#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#define CMD_NUM 16

typedef struct Command {
    const char * cmdName;
    int binCode;
} Command;


extern Command commandTable[CMD_NUM];

#endif