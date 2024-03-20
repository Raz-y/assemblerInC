#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "macro_parser.h"
#include "assembler.h"
#include "utils.h"

Command commandTable[CMD_NUM] =
        {
                {"mov",0},
                {"cmp", 1},
                {"add", 2},
                {"sub", 3},
                {"not", 4},
                {"clr", 5},
                {"lea", 6},
                {"inc", 7},
                {"dec", 8},
                {"jmp", 9},
                {"bne", 10},
                {"red", 11},
                {"prn", 12},
                {"jsr", 13},
                {"rts", 14},
                {"hlt", 15}
        };


/* main: assembler*/

int main(int argc, char *argv[]){

  FILE *origin;
  FILE *fp, *mc;
  char *fileName;
  char *prog = argv[0];
  char copyFileName[] = "copy.asm";

  /* check if file was given */
  if(argc == 1 ){
    fprintf(stderr, "Error: No file given, expected 1 input file\n");
    exit(1);
  }
  /* check if file can be opened */
  if((origin = fopen(*++argv, "r")) == NULL){
    fprintf(stderr, "%s: Can't open %s\n", prog, *argv );
    exit(1);
  }

  fileName = *argv;
  fprintf(stdout, "%s opened successfully\n\n", fileName);

  if ((fp = fopen(copyFileName, "w+")) == NULL) {
      fprintf(stderr, "Failed to create a copy of the file.\n");
      fclose(origin);
      exit(1);
  }

    /*fileCopy(origin, fp);*/
    skipAndCopy(origin, fp);
    fclose(origin);
    fprintf(stdout, "Copy created successfully, processing copy....\n");

    printFile(fp);
    rewind(fp);


    fprintf(stdout, "\n--------- Running Assembler ----------\n");

    macroParser(fp);
    fclose(fp);

    mc = fopen("parsedMacro.asm", "r");
    if(mc == NULL){
        fprintf(stderr, "couldn't open macro file\n");
    }
    printFile(mc);
    fclose(mc);

    return 0;

} /* end of main */

