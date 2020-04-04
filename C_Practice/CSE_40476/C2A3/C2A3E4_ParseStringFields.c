#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName);

int main(void)
{
   FILE *fp = OpenFile("TestFile10.txt");
   char *buf = (char *)malloc(sizeof(char)*255);
   buf = fgets(buf, 255, fp);
   while(buf != NULL)
   {
      printf("%s\n", buf);
      buf = fgets(buf, 255, fp);
   }
   return 0; 
}
