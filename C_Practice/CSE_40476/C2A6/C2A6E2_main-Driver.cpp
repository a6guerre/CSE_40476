#define INSTRUCTOR_FILE    // DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE

/***  YOU DO NOT NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS  ***/

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

//****************************************************************************
// Everything in this file was written to help test/verify your code and must
// not be altered in any way.  Do not rename this file or copy anything from
// it into your file(s).  This file does not necessarily represent good coding
// technique, proper formatting/style, or meet the requirements your code must
// meet.  You do not need to understand the code in this file to write yours.
//****************************************************************************
#ifdef INSTRUCTOR_FILE

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cfloat>
using namespace std;

const float MIN_SET = -1e-30F;
const float MIN_TEST = MIN_SET + 0.1e-30F;
const float MAX_SET = +1e+30F;
const float MAX_TEST = MAX_SET - 0.1e+30F;

float *SortValues(float *first, size_t elements);
float *GetValues(float *first, size_t elements);

static float *DisplayValues(float *first, size_t elements);

int main()
{
   const int SZ1 = 10;
   const int SZ2 = 7;
   const int SZ3 = 5;
   float array1[SZ1 + 2];
   float array2[SZ2 + 2];
   float array3[SZ3 + 2];
   bool gotError = false;

   array1[0] = MIN_SET;
   array2[0] = MIN_SET;
   array3[0] = MIN_SET;
   array1[SZ1 + 1] = MAX_SET;
   array2[SZ2 + 1] = MAX_SET;
   array3[SZ3 + 1] = MAX_SET;

   if (!DisplayValues(SortValues(GetValues(array1 + 1, SZ1), SZ1), SZ1))
      gotError = true;
   if (!DisplayValues(SortValues(GetValues(array2 + 1, SZ2), SZ2), SZ2))
      gotError = true;
   if (!DisplayValues(SortValues(GetValues(array3 + 1, SZ3), SZ3), SZ3))
      gotError = true;

   if (gotError)
      return EXIT_FAILURE;
   return EXIT_SUCCESS;
}

float *DisplayValues(float *first, size_t elements)
{
   bool gotError = false, gotDifferentValue = false;
   float previous = *first, firstVal = *first, *ptr, *end = first + elements;

   if (first[-1] > MIN_TEST || first[elements] < MAX_TEST)
   {
      cerr << "Error - Out-of-bounds array access\n\n";
      return NULL;
   }

   for (ptr = first; ptr < end; ++ptr) // get each element
   {
      cout << *ptr << '\n';
      if (ptr != first)                // if not first element...
      {
         if (previous < *ptr)          // ...check sort order
         {
            gotError = true;
            break;
         }
         if (*ptr != firstVal)
            gotDifferentValue = true;
      }
      previous = *ptr;                 // save this element
   }
   if (gotError || !gotDifferentValue)
   {
      cerr << "Error - Array sorted incorrectly\n\n";
      return NULL;
   }
   cout << "Array sorted correctly!\n\n";
   return first;
}
#endif
