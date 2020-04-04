#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
   char *temp = (char *)malloc(size);

   // let's copy contents of pa into temp
   memcpy(temp, pa, size);

   // let's copy contents of pb into pa
   memcpy(pa, pb, size);

   // let's copy original contents of pa into pb
   memcpy(pb, temp, size);

}

void print_arrays(char *a, char* b, size_t size)
{
   for(int i = 0; i < size; ++i)
      printf("%d\n", a[i]);
   printf("---------------------\n");
   for(int i = 0; i < size; ++i)
      printf("%d\n", b[i]);

}

int main(void)
{
   char arr1[] = {4,5,6};
   char arr2[] = {7,8,9};
  
//   printf("%d\n",  sizeof(arr1)/sizeof(arr1[0]));
   print_arrays(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
   SwapObjects(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]) );

   printf(" ---------------------\n");

   print_arrays(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
   return 0;
}
