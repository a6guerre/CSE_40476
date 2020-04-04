#include <stdlib.h>
#include <stdio.h>

#define  FILENAME "TestFile10.txt"
#define  MAX_BUFFER 100
FILE *OpenFile(const char *fileName);

int main(void)
{
   FILE *fopen = OpenFile(FILENAME);
   char *line_buf;
   if((line_buf = malloc(MAX_BUFFER*sizeof(char))) == NULL)
   {
      fprintf(stderr, "Out of memory\n");
      return -1;
   }
   size_t line_size;
   getline(&line_buf, &line_size, fopen)
   printf("%s\n", line_buf);
   return 0;
}
