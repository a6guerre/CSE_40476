#include <stdio.h>
#include <stdlib.h>
#include "C2A6E4_List-Driver.h"

FILE *OpenFile(const char *fileName)
{
   FILE *inFile;
   if((inFile = fopen(fileName, "r")) == NULL)
   {
      printf("Error\n");
      exit(EXIT_FAILURE);
   }
   return inFile;
}
