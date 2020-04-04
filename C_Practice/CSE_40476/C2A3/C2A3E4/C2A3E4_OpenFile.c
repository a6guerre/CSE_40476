#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
   FILE *inFile = fopen(fileName, "r");
   if(inFile == NULL)
   {
      printf("Failure in opening file %s", fileName);
      exit(EXIT_FAILURE);
   }
   
}
