#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *ReverseEndian(void *ptr, size_t size);

void *ReverseEndian(void *ptr, size_t size)
{
   char *end, *tail, temp;
  // printf("Address is at %x \n", ptr);
   tail = (char *)ptr + size - 1;
  // printf("address of tail is at %x\n", tail);
   while(tail > (char *)ptr)
   {
      temp = *(char*)ptr;
      *(char *)ptr = *tail;
      *tail = temp;
      ++ptr;
      --tail;
    //  printf("hi\n");
   }

   return ptr;
}
