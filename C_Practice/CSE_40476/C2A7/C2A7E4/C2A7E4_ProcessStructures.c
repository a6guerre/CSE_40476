#include <stdlib.h>
#include <stdio.h>
#include "C2A7E4_Test-Driver.h"
void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
   ReverseEndian(&ptr->flt, sizeof(float));
   ReverseEndian(&ptr->dbl, sizeof(double));
   ReverseEndian(&ptr->vp, sizeof(ptr->vp));
   return ptr;   
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
  long size;
  if((size = fread(ptr, sizeof(struct Test), count, fp)) != count){
     printf("%i %i\n", count, size);
     exit(EXIT_FAILURE);
  }
  return ptr;
}

struct Test *WriteStructures(struct Test *ptr, size_t count, FILE *fp)
{
   if((fwrite(ptr, sizeof(struct Test), count, fp) != count)){
      printf("Error\n");
    // exit(EXIT_FAILURE);
   }

   return ptr;
}


