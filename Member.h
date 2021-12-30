#pragma once
//#include "DevLibraries.h"
#include "Account.h"
#define MAX_CHECK_OUT 5

class Account;

class Member : public Account {
private:
    unsigned short mTotalCheckOut;

public:
    Member()
    {
        std::cout << "Member\n";
    }
    Member(std::string us, std::string pw) : Account(us, pw)
    {
        std::cout << "Member\n";   
    }
};