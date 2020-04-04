#include <stdio.h>
#include <stdlib.h>
FILE *OpenFileBinary(const char *fileName, FILE *fpointer);

void ListHex(FILE *fpointer, int bytesPerLine)
{
   int buffer;
   fgetc(fpointer);
   printf("%x\n", (char)buffer);
}

int main(void)
{
   FILE *fpointer = NULL;
   fpointer = OpenFileBinary("TestFile4.bin", fpointer);
   ListHex(fpointer, 10);
   return 0;
}
