#pragma once
//#include "DevLibraries.h"
#include "Date.h"
#include <string> 

std::istream& operator>>(std::istream& in, Person&);

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
    std::string toString() const;
    
    bool isThisPerson(std::string username);
    friend std::istream& operator>>(std::istream& in, Person&);
    friend std::ostream& operator<<(std::ostream& os, const Person&);  
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

std::istream& operator>>(std::istream& in, Person& other) 
{
    getline(in, other.pName);
    std::string dOb;
    in >> other.pEmail
       >> other.pPhone
       >> dOb
       >> other.pIdentityCard
       >> other.pAddress
       >> other.pGender;
    other.pDayOfBirth = Date::Parse(dOb);
    return in;
}

std::ostream& operator<<(std::ostream& os, const Person& other) 
{
    os << other.pName << "\n"
       << other.pEmail << "\n"
       << other.pPhone << "\n"
       << other.pDayOfBirth.toString() << "\n"
       << other.pAddress << "\n"
       << other.pGender << "\n";
}

bool Person::isThisPerson(std::string username)
{
    return (pName == username);
}