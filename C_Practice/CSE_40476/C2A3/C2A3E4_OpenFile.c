#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
   FILE *inFile;
   if((inFile = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "Can't open file\n");
      exit(EXIT_FAILURE);
   }
   return inFile;
}

