#pragma once
//#include "DevLibraries.h"
#include "Date.h"
#include <string> 

class Person
{
private:
    std::string pName, pEmail, pPhone, pIdentityCard, pAddress;
    bool pGender;
    Date pDayOfBirth;
public:
    Person();
    Person(std::vector<std::string>);
    bool operator==(const Person&);
    void changeProfile(std::string, std::string, std::string, Date, std::string, std::string, bool);
    string toString() const;
};

Person::Person()
{
    pName = "";
    pEmail = "";
    pPhone = "";
    pIdentityCard = "";
    pAddress = "";
    pGender = false;
    pDayOfBirth = Date(0,0,0);
}

Person::Person(std::vector<std::string> pInfo)
{

}

bool Person::operator==(const Person& other)
{
    return (
            pName           == other.pName 
        &&  pEmail          == other.pEmail
        &&  pPhone          == other.pPhone
        &&  pIdentityCard   == other.pIdentityCard
        &&  pAddress        == other.pAddress
        //&&  pDayOfBirth     == other.pDayOfBirth
        &&  pGender         == other.pGender
    );
}

void Person::changeProfile(std::string Name, std::string Email, std::string Phone, Date DoB, std::string ID, std::string Addr, bool gender)
{
    pName = Name;
    pEmail = Email;
    pPhone = Phone;
    pDayOfBirth = DoB;
    pIdentityCard = ID;
    pAddress = Addr;
    pGender = gender;
}

std::string Person::toString() const
{
    // return information of this person
    return "<Install now>";
}