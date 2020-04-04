#include <stdio.h>
#include <stdlib.h>

FILE *OpenFileBinary(const char *fileName, FILE *fpointer)
{
   if((fpointer = fopen(fileName, "rb")) == NULL)
   {
      printf("Error\n");
      exit(EXIT_FAILURE);
   }
   return fpointer;
}
