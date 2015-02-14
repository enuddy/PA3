#include "person.h"


Person::Person()
{
  mId = "";
  mName = "";
  mPhoneNumber = "";
}

Person::Person(string id, string name, string phoneNumber)
{
  mId = id;
  mName = name;
  mPhoneNumber = phoneNumber;
}

Person::~Person()
{
}

string Person::getID()
{
  return mId;
}

string Person::getName()
{
  return mName;
}

string Person::getPhoneNumber()
{
  return mPhoneNumber;
}

void Person::setID(string newId)
{
  mId = newId;
}

void Person::setName(string newName)
{
  mName = newName;
}

void Person::setPhoneNumber(string newPhone)
{
  mPhoneNumber = newPhone;
}

bool Person::operator==(string id)
{
  return mId == id;
}

bool Person::operator==(Person rhs)
{
  return mId == rhs.mId;
}
