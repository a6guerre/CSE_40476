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
#include <fstream>
using std::ifstream;

ifstream *OpenFiles(char * const fileNames[], size_t count);
void MergeAndDisplay(ifstream files[], size_t count);

int main(int argc, char *argv[])
{
   const int FILE_NAME1_ARG_NO = 1;    // command line arg: first file name

   ifstream *files = OpenFiles(&argv[FILE_NAME1_ARG_NO], size_t(argc - 1));
   MergeAndDisplay(files, size_t(argc - 1));
   delete[] files;

   return EXIT_SUCCESS;
}
#endif
