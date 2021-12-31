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
    std::string aID, aUsername, aPassword;
    Person aInfo;
    std::vector<std::string> aBooksBorrowed;
    AccountStatus aStatus;
public:
    Account();
    Account(std::string ID, std::string US, std::string Pass, Person info);
    bool checkLogOut(std::string US, std::string Pass);
    bool changePass(std::string Pass);
    bool resetPass();
    bool updateProfile(vector<string> profile);
    bool blockAccount();
    void updateBooksBorrowed(std::vector<std::string> list);
    std::vector<std::string> displayBorrowedBooks();
    string toString() const;
};

Account::Account()
{
    aID = "";
    aUsername = "";
    aPassword = "";
    aInfo = Person();
    aStatus = Active;
}

Account::Account(std::string ID, std::string US, std::string Pass, Person info)
{
    aID = ID;
    aUsername = US;
    aPassword = Pass;
    aInfo = info;
    aStatus = Active;
}

bool Account::checkLogOut(std::string US, std::string Pass)
{
    
}
