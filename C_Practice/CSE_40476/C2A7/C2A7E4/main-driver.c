#include <stdio.h>
#include <stdlib.h>

#include "C2A7E4_Test-Driver.h"

FILE *OpenTemporaryFile(void);
struct Test *ReverseMembersEndian(struct Test *ptr);
struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp);
struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp);

#define Elements(array) (sizeof(array)/sizeof((array)[0]))

typedef unsigned char UChar;

int main(void)
{
   const char * const MESSAGE = "Error in WriteStructures or ReadStructures\n";
   UChar *cp;
   int elemNo;
   size_t byteNo;
   FILE *temporaryFile;
   int gotError = 0;

   struct Test x[] =
   { 
      {23.6, -425e-6, (void *)0x2345},
      {2,1,0},
      {-6,3.3, NULL}
   };

   struct Test y[Elements(x)] =
   {
      {123.456F, 789.12, (void*)0x9876},
      {69.0F, 24, (void *) 0x1928A},
      {-59.2F, 89.48e-16, (void *) 0xABC}
   };

   size_t fileSize;

   temporaryFile = OpenTemporaryFile();
   WriteStructures(x, Elements(x), temporaryFile);
   rewind(temporaryFile);
   for(fileSize = 0; fgetc(temporaryFile) != EOF; ++fileSize)
	   ;
   if (fileSize != sizeof(x))
   {

     printf("error");
     gotError = 1;
   }

   rewind(temporaryFile);
   ReadStructures(y, Elements(y), temporaryFile);
   printf("\n");

   printf("Structures before (1st line) & after (2nd line) reversal:\n\n");
   for (elemNo = 0; elemNo < (int) Elements(x); ++elemNo, putchar('\n'))
   {
      y[elemNo] = x[elemNo];
      ReverseMembersEndian(&y[elemNo]);
      printf("Element %d: \n", elemNo);
      printf(" ");
      cp = (UChar *)&x[elemNo];
      for (byteNo = 0; buteNo < sizeof(*x); ++byteNo)
	      printf(" %02x", (unsigned) cp[byteNo]);
      printf
   }
   return EXIT_SUCCESS;
}
