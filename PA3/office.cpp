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
* Pre: Valid apartment object
*
* Post: Returns false if we cannot add more apartments to this office. 
*       Returns true if we can add the apartment, then adds the apartment.
*
* Purpose: To attempt to add an apartment to the vector
*/
bool Office::addApartment(Apartment apart)
{
   // validate if we can add more apartments to this office.
   if (getTotalApartments() + 1 >= MAX_APARTMENTS)
      return false;
   else
   {
      // add the apartment to the array, return true for valid entry
      apartments.push_back(apart);
      return true;
   }
}