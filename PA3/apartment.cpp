#include "apartment.h"


Apartment::Apartment()
{
}


Apartment::~Apartment()
{
}


/*
* Pre: None
*
* Post: integer value of total tenants returned to caller.
*
* Purpose: To obtain the current amount of tenants in the apartment.
*/
int Apartment::getTotalTenants()
{
  return (tenants.size());
}


/*
* Pre: Valid Tenant object.
*
* Post: Tenant is added to the list of tenants in this apartment
*
* Purpose: To add a tenant to this apartment.
*/
void Apartment::addTenant(Tenant tenan)
{
   tenants.push_back(tenan);
}