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
#include <iomanip>
#include <iostream>
using namespace std;

#include "C2A5E4_StatusCode-Driver.h"

const char * const FILENAME = "TestFile5.txt";

void OpenFile(const char *fileName, ifstream &inFile);
StatusCode DetectFloats(const char *chPtr);

int main()
{
   const int BUFSIZE = 128;                 // input string buffer size
   const int SAFEBUF = BUFSIZE - 1;         // limit input string
   char buf[BUFSIZE];                       // input buffer
   ifstream inFile;

   OpenFile(FILENAME, inFile);

   // Get one string at a time and pass it to the parser function.
   for (int stringNo = 1; inFile >> setw(SAFEBUF) >> buf; ++stringNo)
   {
      cout << setw(25) << buf;
      switch (DetectFloats(buf))
      {
      case NO_MATCH:
         if (stringNo >= 2 && stringNo <= 19)
            cout << " <-- ERROR - THIS STRING IS VALID***";
         cout << "\n";
         break;
      case TYPE_FLOAT:
         cout << " <--- decimal float";
         if (stringNo < 2 || stringNo > 7)
            cout << "  ***ERROR - WRONG RESULT***";
         cout << "\n";
         break;
      case TYPE_DOUBLE:
         cout << " <--- decimal double";
         if (stringNo < 8 || stringNo > 14)
            cout << "  ***ERROR - WRONG RESULT***";
         cout << "\n";
         break;
      case TYPE_LDOUBLE:
         cout << " <--- decimal long double";
         if (stringNo < 15 || stringNo > 19)
            cout << "  ***ERROR - WRONG RESULT***";
         cout << "\n";
         break;
      default:
         cout << "*****internal error*****\n";
         break;
      }
   }

   inFile.close();
   return EXIT_SUCCESS;
}
#endif
