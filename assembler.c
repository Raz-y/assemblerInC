#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "macro_parser.h"
#include "assembler.h"
#include "utils.h"



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

    fileCopy(origin, fp);
    fclose(origin);
    fprintf(stdout, "Copy created successfully, processing this copy....\n");


    printFile(fp);

    rewind(fp);

    fp = skip(fp);

    fprintf(stdout, "\n-------------------\n");

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

