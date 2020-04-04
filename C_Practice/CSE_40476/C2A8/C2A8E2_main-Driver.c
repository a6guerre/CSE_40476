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

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_IX 1        // argv index for input file name
#define TOTAL_ARGS 2          // number of command line arguments

void DisplayModifiedSingleReals(FILE *inFile);
FILE *OpenFileBinary(const char *fileName);

int main(int argc, char *argv[])
{
   FILE *fp;

   if (argc < TOTAL_ARGS)
   {
      fprintf(stderr, "Syntax is: <pgmName> <fileName>\n");
      exit(EXIT_FAILURE);
   }
   fp = OpenFileBinary(argv[FILE_NAME_IX]);
   DisplayModifiedSingleReals(fp);
   fclose(fp);
   return EXIT_SUCCESS;
}
#endif
