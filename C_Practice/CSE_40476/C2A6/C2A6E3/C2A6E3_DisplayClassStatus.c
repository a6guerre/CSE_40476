#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void *elemA, const void *elemB)
{
//   printf("%s and %s \n", *(const char **)elemA, *(const char **)elemB);
//   printf("sizes: %d and %d\n", sizeof((const char **)elemA),  sizeof((const char **)elemB)); 
   int test = strcmp( *(const char **) elemA, *(const char **) elemB);
//   printf("%d\n", test);
   return test; 
}

void SortStudents(const char *studentList[], size_t studentCount)
{
   printf("Sorting now \n");
   qsort(&studentList[0], studentCount, sizeof(studentList[0]), Compare);
}

void DisplayClassStatus( const char *registrants[], size_t registrantCount, 
		         const char *attendees[], size_t attendeeCount)
{
   printf("Test string %s\n", registrants[0]);
   for(int idx = 0; idx < attendeeCount; ++idx)
   {
      if(bsearch(&registrants[idx], &attendees[0], attendeeCount, sizeof(attendees[0]), Compare) == NULL)

      {
         printf("Not Found: %s\n", registrants[idx]);
      }
   }	 
   
}
