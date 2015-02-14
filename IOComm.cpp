#include "IOComm.h"


IOComm::IOComm()
{
}


IOComm::~IOComm()
{
}


void IOComm::attemptBackspace(string &responseToReduce)
{
   // see if we can even reduce our current string at all.
   if (responseToReduce.length() > 0)
   {
      responseToReduce.pop_back();
      consoleBackspace();
   }
}




/*
* Pre: None
*
* Post: appropriatly move the cursos back one space on the console.
*
* Purpose: moves the console back one space and clears it at the same time,
*          so you're not seeing the char you just deleted.
*/
void IOComm::consoleBackspace()
{
   // move cursor back one space
   cout << '\b';
   // replace the character at the space with a blank.
   cout << ' ';
   // move the cursor back to its original place.
   cout << '\b';
}



/*
* Pre: None
*
* Post: A string containing only integers / letters is returned.
*
* Purpose: To only accept integers / letters as a response, then to make
*          those into a string and return the value.
*/
string IOComm::getAlphaNumericResponse()
{
   string response = "";
   char entered = ' ';

   entered = _getch();
   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      if (isalnum(entered))
      {
         response.push_back(entered);
         cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: otherKeys is populated with values, size = the length of otherKeys[]
*
* Post: A string containing only integers / letters / any of the
*       specific other keys is returned.
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
string IOComm::getAlphaNumericResponseOr(const char otherKeys[], int size)
{
   string response = "";
   char entered = ' ';

   // get an initial value.
   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }
      // check to see if a valid number, if so add it to the string
      if (isalnum(entered))
      {
         response.push_back(entered);
         cout << entered;
      }
      else
      {
         for (int i = 0; i < size; i++)
         {
            if (otherKeys[i] == entered)
            {
               response.push_back(entered);
               cout << entered;
            }
         }
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: None
*
* Post: A string containing only letters is returned.
*
* Purpose: To only accept letters as a response, then to make those into a
*          string and return the value.
*/
string IOComm::getAlphaResponse()
{
   string response = "";
   char entered = ' ';

   entered = _getch();
   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      if (isalpha(entered))
      {
         response.push_back(entered);
         cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: bool on whether you want spaces or not
*
* Post: A string containing only letters is returned. and spaces if space = true
*
* Purpose: To only accept letters as a response, then to make those into a
*          string and return the value. Includes spaces if bool is true.
*/
string IOComm::getAlphaResponse(bool spaces)
{
   string response = " ";

   if (spaces)
   {
      char space[] = {' '};
      response = getAlphaResponseOr(space, 1);
   }
   else
   {
      response = getAlphaResponse();
   }

   return response;
}


/*
* Pre: otherKeys is populated with values, size = the length of otherKeys[]
*
* Post: A string containing only letters / any of the
*       specific other keys is returned.
*
* Purpose: To only accept alpha chars and the specific other keys as a response,
*          then to make those into a string and return the value.
*/
string IOComm::getAlphaResponseOr(const char otherKeys[], int size)
{
   string response = "";
   char entered = ' ';

   // get an initial value.
   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }
      // check to see if a valid number, if so add it to the string
      if (isalpha(entered))
      {
         response.push_back(entered);
         cout << entered;
      }
      else
      {
         for (int i = 0; i < size; i++)
         {
            if (otherKeys[i] == entered)
            {
               response.push_back(entered);
               cout << entered;
            }
         }
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: options is populated, optionsize = options length
*      all values in options MUST be capitalized.
*
* Post: A char the user selected that is equivilent to one of the options
*
* Purpose: To only accept specific letters as a response, then to return that
*          value to the user as an upper case letter.
*/
char IOComm::getCharResponse(const char options[], int optionSize)
{
   string letter = ""; // string to make it easier to check values.
   char input = ' ';
   input = _getch();

   while (input != ENTER_KEY_VALUE || letter.length() == 0)
   {
      // Check for and handle if backspace was input.
      if (isBackspaceEntered(input))
         attemptBackspace(letter);
      else
      {
         // check to see if a letter. And that we don't already have an option
         if (isalpha(input) && letter.length() == 0)
         {
            // normalize data.
            input = static_cast<char>(toupper(input));

            // loop through options.
            for (int i = 0; i < optionSize; i++)
            {
               // if one of the letters looking for.
               if (input == options[i])
               {
                  letter.push_back(input);
                  cout << input;
                  break;
               }
            }
         }
      }

      // check for another input
      input = _getch();
   }

   return letter.at(0);
}


/*
* Pre: None
*
* Post: A string is returned.
*
* Purpose: To accept an input and to mask the input with * as they are entered.
*/
string IOComm::getMaskedResponse()
{
   string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      response.push_back(entered);
      cout << "*";

      entered = _getch();
   }

   return response;
}


/*
* Pre: None
*
* Post: A string containing only integers is returned.
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
string IOComm::getNumericResponse()
{
   string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      // only accept digits and only if the length is low enough to accept more.
      if (isdigit(entered))
      {
         response.push_back(entered);
         cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: size of the numeric response you want back.
*
* Post: A string containing only integers is returned. and is = size
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
string IOComm::getNumericResponse(int size)
{
   string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE || response.length() != size)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      // only accept digits and only if the length is low enough to accept more.
      if (isdigit(entered) && response.length() < size)
      {
         response.push_back(entered);
         cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: The character entered.
*
* Post: True if backspace or delete are entered, otherwise false
*
* Purpose: To inform you if the letter the user entered is indicating a desire
*          to move backwards one char in their input.
*/
bool IOComm::isBackspaceEntered(char input)
{
   if (input == DELETE_KEY_VALUE || input == BACKSPACE_KEY_VALUE)
      return true;
   else
      return false;
}