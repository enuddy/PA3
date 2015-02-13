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

Person::string getId()
{
  return mId;
}

Person::string getName()
{
  return mName;
}

Person::string getPhoneNumber()
{
  return mPhoneNumber;
}

Person::void setID(string newId)
{
  mId = newId;
}

Person::void setname(string newName)
{
  mName = newName;
}

Person::void setPhoneNumber(string newPhone)
{
  mPhoneNumber = newPhone;
}

Person::bool operator==(string id)
{
  return mId == id;
}

Person::bool operator==(Person rhs)
{
  return mId == rhs.mId;
}

}
}
}
}
}
}
}
