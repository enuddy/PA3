#ifndef IOCOMM_H
#define IOCOMM_H

#include <iostream>
#include <conio.h>

using namespace std;

const int BACKSPACE_KEY_VALUE = 127;
const int DELETE_KEY_VALUE = 8;
const int ENTER_KEY_VALUE = 13;

class IOComm
{

public:
   IOComm();
   ~IOComm();

   void attemptBackspace(string &responseToReduce);

   void consoleBackspace();

   string getAlphaNumericResponse();

   string getAlphaNumericResponseOr(const char otherKeys[], int size);

   string getAlphaResponse();

   string getAlphaResponseOr(const char otherkeys[], int size);

   char getCharResponse(const char options[], int optionSize);

   string getMaskedResponse();

   string getNumericResponse();

   string getNumericResponse(int size);

   bool isBackspaceEntered(char input);
};

#endif