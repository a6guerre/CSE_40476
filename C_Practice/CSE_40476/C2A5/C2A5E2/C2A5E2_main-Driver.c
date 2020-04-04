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

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "C2A5E2_Type-Driver.h"

#define DIM_MAX 27
#define DIM_STEP 1
#define ROW_COUNT_START 1
#define COL_COUNT_START DIM_MAX

Type **Create2D(size_t rows, size_t cols);
void Free2D(void *p);
static int Test2D(Type **ppObj, int dim0, int dim1);

int main(void)
{
   Type **ppObj, **ppObj2;
   int rows, cols, gotFailure = 0;

   for (
      rows = ROW_COUNT_START, cols = COL_COUNT_START;
      rows < DIM_MAX && cols > 0;
      rows += DIM_STEP, cols -= DIM_STEP
       )
   {
      int failed;
      // Create a 2D array of "Objects" dynamically.
      ppObj = Create2D(2, 2);

      // Test it and print the results.
      failed = Test2D(ppObj,2, 2);
      // Free the array.
      Free2D((void *)ppObj);
      if (failed)
      {
         gotFailure = 1;
         fprintf(stderr, "Create2D(%d, %d) failed\n", rows, cols);
      }
      else
         printf("Create2D(%d, %d) succeeded\n", rows, cols);
   }
   if (gotFailure)
      return EXIT_FAILURE;
   return EXIT_SUCCESS;
}

int Test2D(Type **ppObj, int dim0, int dim1)
{
   signed char testValue;
   int row, col, ix;
   int error;
   Type *pObj;
   Type item;
  //  ppObj[1] = (Type *)(ppObj[0][dim1]);
   printf("%x  \n", &ppObj[1][0][0]);
   // Fill up the array with known values using 2D syntax.
   testValue = SCHAR_MIN;
   for (row = 0; row < dim0; ++row)
   {
      for (col = 0; col < dim1; ++col)
      {
         // For this to work Type must be a 1D array type.
         for (ix = 0; ix < (int)(sizeof(item)/sizeof(item[0])); ++ix)
         {
	    printf("%x  ", &ppObj[row][col][ix]);
	    printf("%d %d\n", row, col);
	    printf("testvalue: %d\n", testValue);
           // ppObj[1] = (Type *)(ppObj[0][dim1]);
            
            ppObj[row][col][ix] = testValue;
            printf("ppObj val: %d testValue  %d\n", ppObj[row][col][ix], testValue);
            if (testValue == SCHAR_MAX)
               testValue = SCHAR_MIN;
            else
               ++testValue;
         }
      }
   }
   printf("row: %d, col:%d, ix:%d adress of pobj %x\n", row, col, ix, &ppObj[row][col][ix] );
   //   printf("\n\n\n\n");
   // Verify the stored values using a compact pointer.
   error = 0;
   testValue = SCHAR_MIN;
   int j = 0;;
     for (pObj = (Type *)(ppObj + dim0);
      pObj < (Type *)&ppObj[dim0 - 1][dim1]; ++pObj){
   
     
      // For this to work Type must be a 1D array type.
      for (ix = 0; ix < (int)(sizeof(item)/sizeof(item[0])); ++ix)
      {
         printf("addr: %x    %4d\n", &(*pObj)[ix] ,(*pObj)[ix]);
	 printf("idx: %d  j: %d\n", ix, j);
	 printf("Test val: %d\n", testValue);
         if ((signed char)(*pObj)[ix] != testValue)
         {
            error = 1;
           // break;
         }
         if (testValue == SCHAR_MAX)
            testValue = SCHAR_MIN;
         else
            ++testValue;
      }
      if (error)
       //  break;
      ++j;
   }

testValue = SCHAR_MIN;
   for (row = 0; row < dim0; ++row)
   {
      for (col = 0; col < dim1; ++col)
      {
         // For this to work Type must be a 1D array type.
         for (ix = 0; ix < (int)(sizeof(item)/sizeof(item[0])); ++ix)
         {
	    printf("%x  ", &ppObj[row][col][ix]);
	    printf("%d %d\n", row, col);
	    printf("testvalue: %d\n", testValue);
           // ppObj[1] = (Type *)(ppObj[0][dim1]);
            
            //ppObj[row][col][ix] = testValue;
            printf("2ndppObj val: %d testValue  %d\n", ppObj[row][col][ix], testValue);
            if (testValue == SCHAR_MAX)
               testValue = SCHAR_MIN;
            else
               ++testValue;
         }
      }
   }

   // Return a success or an error code.
   return error;
   //lint -e{550} suppress "'item' not accessed"
}
#endif
