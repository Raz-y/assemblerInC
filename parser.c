#include <stdio.h>
#include <ctype.h>
#include "parser.h"

/* skip white characters

FILE *skip (FILE *fp){
  int c;
  while((c = getc(fp)) != EOF){
    if(isspace(c)){
      continue;
    } else if (c == ';'){
      while ((c = getc(fp)) != EOF && c != '\n'){
        ;
      }
    } else {
      ungetc(c, fp);
      break;
    }
  }


  return fp;
}

*/

