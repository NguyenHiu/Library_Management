#pragma once
//#include "DevLibraries.h"
#include <string> 

class Person
{
private:
    std::string _pName, _pEmail, _pPhone, _pBirthDay, _pCMND, _pAddress;
    bool _sex;
public:
    Person(std::string name, std::string email, std::string phone, std::string birthDay, std::string CMND, std::string address, bool sex)
    {
        _pName = name; _pEmail = email; _pPhone = phone;
        _pBirthDay = birthDay; _pCMND = CMND; _pAddress = address;    
        _sex = sex;
    }
};
