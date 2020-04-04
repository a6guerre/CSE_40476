#include <stdio.h>
#include <stdlib.h>

FILE *OpenTemporaryFile(void)
{
   FILE *filePointer;
   if((filePointer = tmpfile()) == NULL)
   {
      printf("Failure to open file\n");
      exit(EXIT_FAILURE);
   }
   return filePointer;
}
