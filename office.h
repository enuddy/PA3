#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include <vector>
#include <string>

#include "agent.h"
#include "apartment.h"
#include "tenant.h"
#include "IOComm.h"

using namespace std;


/* The max amount of agents that an office can have. */
const int MAX_AGENTS = 10;

/* The max amount of Apartments an office can have. */
const int MAX_APARTMENTS = 1000;

/* The max amount of Tenants an office can have. */
const int MAX_TENANTS = 5000;

// Office Class
class Office
{

private:
   
   /* The vector to store all the apartments in the office. */
   vector<Apartment> apartments;

   /* The vector to store all the agents in the office. */
   vector<Agent> agents;

   IOComm io;

public:
   Office();
   ~Office();

   // Accessors
   
   int getTotalAgents();

   int getTotalApartments();
   
   int getTotalTenants();

   // Mutators

   bool addApartment();


   // Misc.

   void loadOffice();

   string promptAddress();

};


#endif
