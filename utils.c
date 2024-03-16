#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

/* make a duplicate of s */
char *strdup(char *s) {
  char *p;
  p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
  return p;
 }




/* fileCopy: copy file ifp to file ofp */
void fileCopy(FILE *ifp, FILE *ofp) {
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

/* printFile: print file content */

void printFile(FILE *fp){
    int c;
    rewind(fp);
    while((c= getc(fp)) != EOF){
        putc(c, stdout);
    }
}



