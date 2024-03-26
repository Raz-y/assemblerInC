#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"


/* names of registers in CPU */
char *registers[] = {"r1", "r2", "r3", "r4", "r5", "r6", "r7"};





Command commandTable[CMD_NUM];
        {
                {"mov",0, 2},
                {"cmp", 1, 2},
                {"add", 2, 2},
                {"sub", 3, 2},
                {"not", 4, 1},
                {"clr", 5, 1},
                {"lea", 6, 2},
                {"inc", 7, 1},
                {"dec", 8, 1},
                {"jmp", 9, 1},
                {"bne", 10, 1},
                {"red", 11, 1},
                {"prn", 12, 1},
                {"jsr", 13, 1},
                {"rts", 14, 0},
                {"hlt", 15, 0}
        };




