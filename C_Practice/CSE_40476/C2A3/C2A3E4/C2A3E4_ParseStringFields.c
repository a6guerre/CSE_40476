#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS "AEIOUaeiou\t\n"
#define MAX_SIZE 255

void ParseStringFields(FILE *fp)
{
   char *buff = malloc(255);
   char *out  = malloc(255);
   int second = 0;
   while(fgets(buff, MAX_SIZE, fp))
   {
      memcpy(out, buff, strlen(buff) +1);
     //printf("%s\n", buff);  
     // if (second)
//	      break;
      while((buff = strtok(buff,DELIMITERS)))
      {
         printf("%s\n", buff);
	 buff = NULL;
      }
      buff = calloc(255,1); 
      second = 1;
   } 
}
