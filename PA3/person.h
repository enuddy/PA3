#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
   private: 
      string mId, mName, mPhoneNumber;
   public:
      Person();
      Person(string id, string name, string phoneNum);
      ~Person();
      
      string getID();
      string getName();
      string getPhoneNumber();
      
      void setID(string id);
      void setName(string name);
      void setPhoneNumber(string phoneNumber);
      
      bool operator==(string id);
      bool operator==(Person rhs);
   
      friend bool operator==(string lhs, Person rhs);
      friend ostream& operator<<(ostream& output, Person& obj);
      friend istream& operator>>(istream& input, Person& obj);
};

#endif
