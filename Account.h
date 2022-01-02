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

public:
    bool checkLogOut(std::string US, std::string Pass);
    bool changePass(std::string Pass);
    bool resetPass();
    bool updateProfile(std::vector<std::string> profile);
    bool blockAccount();
    void updateBooksBorrowed(std::vector<std::string> list);
    std::vector<std::string> displayBorrowedBooks();
    std::string toString() const;
    std::string getID();
     
    std::string getUserName(); // Hàm này hỗ trợ loadCurUserInfo() trong việc lấy Username ra so sánh
    void setInfo(Person info);
    Person getInfo();
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

std::string Account::getID()
{
    return this->aID;
}

bool Account::checkLogOut(std::string US, std::string Pass)
{
    return (
        aUsername == US
    &&  aPassword == Pass
    );
}

bool Account::changePass(std::string Pass)
{
    aPassword = Pass;
    return true;
}

bool Account::resetPass()
{
    aPassword = "Default-Password";
    return true;
}

bool Account::updateProfile(std::vector<std::string> profile)
{
    // chua biet profile co bao gom aInfo va aBooksBorrowed khong
}

bool Account::blockAccount()
{
    aStatus = Canceled;
    return true;
}

void Account::updateBooksBorrowed(std::vector<std::string> bList)
{
    aBooksBorrowed.resize(bList.size());
    aBooksBorrowed = bList;
}

std::vector<std::string> Account::displayBorrowedBooks()
{
    return aBooksBorrowed;
}

std::string Account::toString() const
{
    // toString...
    return "<Install now>";
}

std::string Account::getUserName()
{
    return aUsername;
}

void Account::setInfo(Person info)
{
    aInfo = info;
}

Person Account::getInfo()
{
    return aInfo;
}