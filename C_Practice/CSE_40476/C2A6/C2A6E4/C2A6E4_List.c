#include <stdio.h>
#include <stdlib.h>
#include "C2A6E4_OpenFile.h"
#include "C2A6E4_List-Driver.h"
#include <string.h>

void printList(List *pt)
{
   while(pt != NULL)
   {
      printf("%s count: %i \n", pt->str, pt->count);
      pt = pt->next;
   }
}
List *SearchList(List *head, char *str)
{
   List *pt = head;
   while(pt != NULL)
   {
      if(!strcmp(str, pt->str)){
	 //printf("string match\n");
         break;
      } 
      else{
         pt = pt->next;
      }
   }
   return pt;
}


List *CreateList(FILE *fp)
{
   char *buf = (char *)malloc(sizeof(char)*99);
   char *token;   
   List *pt = NULL, *head = NULL;

   while((fgets(buf, 99, fp)) != NULL)
   {
      //printf("%s", buf);
      buf = strtok(buf," \n");
      size_t strlength;
      while( buf != NULL)
      {    
        // printf("%s\n",buf);
      	 pt = SearchList(head,buf); // arg should be head pointer
	 if (pt == NULL )
	 {  // Not found
             
            pt = (List *)malloc(sizeof(List));
	    pt->str = (char *)malloc(strlen(buf) + 1);   
	    memcpy(pt->str, buf, strlen(buf) + 1);
	    pt->count = 1;
	    pt->next = head;
	    head = pt; // push onto list
	 }
	 else
	 { // Found
	   //printf("String FOund");
           ++pt->count;
	 }
         buf = strtok(NULL," \n"); 
      }
      buf = (char *)realloc(buf,sizeof(char)*99);
   }
   return head;
}

int main(void)
{
   FILE *inFile = OpenFile("TestFile1.txt");
   List *node = CreateList(inFile);
   printList(node);
   return 0;
}

