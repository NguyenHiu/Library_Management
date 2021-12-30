#pragma once
//#include "DevLibraries.h"
#include "Person.h"
#include "Library.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

enum AccountStatus
{
    Active,
    Canceled
};

class Account
{
private:
    std::string aID, aPassword;
    AccountStatus aStatus;
    //Person aInfo;

public:
    Account() { };
    Account(std::string us, std::string pw)
    {
        aID = us; aPassword = pw;
        aStatus = Active;
    }
    virtual ~Account() {};
    
};

