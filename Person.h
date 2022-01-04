#pragma once
//#include "DevLibraries.h"
#include "Date.h"
#include "regex"

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
    std::string getContactInfo();
    std::string getName();
    std::string toString() const;
    std::string getIDCard();
    
    bool isThisPerson(std::string username);
    bool isThisPersonIDC(std::string _id);
    bool hasGender(bool gender);

    // 0 -> Wrong: Username
    // 1 -> Wrong: Email
    // 2 -> Wrong: Phone
    // 3 -> Wrong: ID Card
    // 4 -> Wrong: Address
    // 5 -> Wrong: Day of Birth
    // 6 -> valid
    static int checkInfo(std::vector<std::string> AccInfo);
};
