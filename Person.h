#pragma once
//#include "DevLibraries.h"
#include "Date.h"

//std::istream& operator>>(std::istream& in, Person&);

class Person
{
private:
    std::string pName, pEmail, pPhone, pIdentityCard, pAddress;
    bool pGender;
    Date pDayOfBirth;
public:
    Person();
    Person(std::vector<std::string> info);
    bool operator==(const Person& other);
    void changeProfile(std::string Name, std::string Email, std::string Phone, Date DoB, std::string ID, std::string Addr, bool gender);
    void changeProfile(std::vector<std::string> info);
    std::string toString() const;
    std::string getIDCard();
    
    bool isThisPerson(std::string username);
    bool isThisPersonIDC(std::string _id);
};
