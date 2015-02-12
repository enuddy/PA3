#ifndef APARTMENT_H
#define APARTMENT_H


#include <vector>

#include "tenant.h"

using namespace std;

class Apartment
{

private:
   
   /* The vector containing all the tennants in this apartment. */
   vector<Tenant> tenants;

public:

   Apartment();
   ~Apartment();

   // accessors
   
   int getTotalTenants();

   // mutators

   void addTenant(Tenant tenant);


   // misc
};

#endif