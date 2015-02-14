#include "office.h"


Office::Office()
{
}


Office::~Office()
{
}


/*
* Pre: None
*
* Post: integer value of total agents returned to caller.
*
* Purpose: To obtain the current amount of agents in the office.
*/
int Office::getTotalAgents()
{
   return (agents.size());
}


/*
* Pre: None
*
* Post: integer value of total apartments returned to caller.
*
* Purpose: To obtain the current amount of apartments in the office.
*/
int Office::getTotalApartments()
{
   return (apartments.size());
}


/*
* Pre: None
*
* Post: integer value of total tenants returned to caller.
*
* Purpose: To obtain the current amount of tenants in the office.
*/
int Office::getTotalTenants()
{
   int tenant = 0;

   // add the amount of tenants in each apartment to the counter.
   for (size_t i = 0; i < apartments.size(); i++)
      tenant += apartments[i].getTotalTenants();
   
   return tenant;
}


/*
* Pre: None
*
* Post: Returns false if we cannot add more apartments to this office. 
*       Returns true if we can add the apartment, then adds the apartment.
*
* Purpose: To attempt to add an apartment to the vector
*/
bool Office::addApartment()
{
   // validate if we can add more apartments to this office.
   if (getTotalApartments() + 1 >= MAX_APARTMENTS)
      return false;
   else
   {
      // obtain information for the apartment.
      // id must be generated
      

      // add the apartment to the array, return true for valid entry
      string address = promptAddress();

      //apartments.push_back();
      return true;
   }
}


/*
* Pre: None
*
* Post: Files are loaded into the office
*
* Purpose: To load all the files and fill data within the office. 
*/
void Office::loadOffice()
{

}


/*
* Pre: None
*
* Post: returns string containing the house location 
*
* Purpose: To obtain information on the address of the user.
*/
string Office::promptAddress()
{
   string address = " ";

   cout << "Enter house number: ";
   string houseNumber = io.getNumericResponse();
   cout << endl;

   cout << "Enter type of address (aka street, lane, drive): ";
   string addressType = io.getAlphaResponse();
   cout << endl;

   cout << "Enter " << addressType << " name: ";
   string streetName = io.getAlphaResponse() + " " + addressType;
   cout << endl;

   // TODO allow for spaces.
   cout << "Enter city: ";
   string city = io.getAlphaResponse();
   cout << endl;

   cout << "Enter State Abreviation: ";
   string state = io.getAlphaResponse();
   cout << endl;

   cout << "Enter zip code: ";
   string zip = io.getNumericResponse();
   cout << endl;

   address = houseNumber + " " + streetName + ", " + 
             city + ", " + state + " " + zip;

   return address;
}