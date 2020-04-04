#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

int main(void)
{
   char **strings = NULL;
   char buffer[BUF_SIZE];  // Must work with allocated char array, in order to avoid parsing with seg fault
   char *element;
   printf("enter next string: ");
   size_t length;
   int line_count = 0;
   for( ; scanf("%s", buffer) != EOF; )
   {
      length = strlen(buffer) + 1;
      printf("strlen: %ld\n", length);
      element = (char*) malloc(length);
      memcpy(element, buffer, length);
      ++line_count;
      printf("echo string: %s\n", element);
      strings = (char **)realloc(strings, line_count*sizeof(char *));
      strings[line_count - 1] = element;
    
   }

   return 0;
}
