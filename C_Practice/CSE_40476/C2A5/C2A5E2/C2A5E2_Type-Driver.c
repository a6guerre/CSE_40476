#include <stdio.h>
#include <stdlib.h>
#include "C2A5E2_Type-Driver.h"

void *SafeMalloc(size_t size)
{
   void *ptr;
   if((ptr = malloc(size)) == NULL)
   {
      printf("memory allocation failure\n");
      exit(EXIT_FAILURE);
   }
   return ptr;
}

void Free2D(void *p)
{
   free((Type **)p);
}	
Type **Create2D(size_t rows, size_t cols)
{
   Type **p;
   p = (Type**)SafeMalloc(rows*sizeof(Type*) + cols*sizeof(Type));
   //printf("Address of p, prior to assignment %x\n", p);
   printf("rows %ld   ", rows);
   p[0] = (Type*)(p + rows);
   printf("Address of p, after to assignment %x   %x\n", &p[0], &p[1]);
   printf("size of Type* %ld\n", sizeof(Type *));
   printf("size of Type* %ld\n", sizeof(Type));
   for(int idx = 1; idx < rows; ++idx)
   {
     p[idx] = (Type *)(p[idx - 1][cols]);
     printf("address of p[1] %x\n", p[idx]);
   }
   if(rows >= 2)
   {
    //  printf("Row is greater than 1  ");
    //  p[1][0][0] =  'h';
    //  printf("%x\n", &p[1][0][0]);
   }
   return p;
}

/*int main(void)
{
   Type **p;
   p = Create2D(2,2);
   p[1][1][0] = 'h';
   printf("%c\n", p[1][1][0]);
   return 0;
*/
