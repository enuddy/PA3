#ifndef PERSON_H
#define PERSON_H

class Person
{
   private: 
      string mId, mName, mPhoneNumber;
   public:
      Person();
      Person(string id, string name, string phoneNum);
      ~Person();
      
      getID(): string
      getName(): string
      getPhoneNumber(): string
      
      setId(string id): void
      setName(string name): void
      setPhoneNumber(string phoneNumber): void
      
      operator==(string id): bool
      operator==(Person rhs): bool
   
      friend operator==(string lhs, Person rhs): bool
      friend operator<<(ostream& output, Person& obj): ostream&
      friend operator>>(istream& input, Person& obj): istream&
};

#endif
