#include "Person.h"

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
    pName = pInfo[0];
    pEmail = pInfo[1];
    pPhone = pInfo[2];
    pIdentityCard = pInfo[3];
    pAddress = pInfo[4];
    pGender = (pInfo[5] == "1" ? 1 : 0);
    Date* temp = Date::Parse(pInfo[6]);
    pDayOfBirth = *temp;
    delete temp;
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

void Person::changeProfile(std::vector<std::string> info)
{
    pName = info[0];
    pEmail = info[1];
    pPhone = info[2];
    pIdentityCard = info[3];
    pAddress = info[4];
    pGender = (info[5] == "1" ? 1 : 0);
    Date* temp = Date::Parse(info[6]);
    pDayOfBirth = *temp;
    delete temp;
}

void Person::writeOnFile(std::fstream& f)
{
    f << pName << "," << pEmail << "," 
      << pPhone << "," << pIdentityCard << ","
      << pAddress << "," << pGender << ","
      << pDayOfBirth.toString() << ",";
}

std::string Person::toString() const
{
    std::stringstream os;
    os << "  + Name: " << pName << "\n"
       << "  + Email: " << pEmail << "\n"
       << "  + Phone: " << pPhone << "\n"
       << "  + Identity Card: " << pIdentityCard << "\n"
       << "  + Address: " << pAddress << "\n"
       << "  + Gender: " << pGender << "\n"
       << "  + Birthday: " << pDayOfBirth.toString() << "\n";
    return os.str();
}

bool Person::isThisPerson(std::string username)
{
    return (pName == username);
}