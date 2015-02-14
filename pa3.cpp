#include "header.h"
#include "office.h"
#include <string>

int main()
{
   Office of;

   string address = of.promptAddress();

   cout << address << endl;

   system("pause");
   return 0;
}