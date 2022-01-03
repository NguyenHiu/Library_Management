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
    void writeOnFile(std::fstream& fo);
    std::string toString() const;
    
    bool isThisPerson(std::string username);
    //friend std::istream& operator>>(std::istream& in, Person&);
    //friend std::ostream& operator<<(std::ostream& os, const Person&);  
};
