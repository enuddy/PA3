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

   // loop through all the apartments and collect their tenant amount. TODO

   return tenant;
}