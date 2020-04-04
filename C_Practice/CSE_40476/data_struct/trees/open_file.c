#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(char *fileName)
{
   FILE *inFile;
   if((inFile = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "Can't open %s\n", fileName);
      exit(EXIT_FAILURE);
   }
   
   return inFile;
}
