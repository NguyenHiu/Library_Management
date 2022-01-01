#pragma once
#include "Utility.h"
#include "Account.h"
#include <fstream>
#include <iostream>

class User
{
public:
    std::string user, pass, ID;
    AccountStatus status;
public:
    User(std::string us, std::string pw, std::string id) {
        user = us;
        pass = pw;
        ID = id;
    }
    bool isThisUser(std::string username) {
        return (username == user);
    }
};

class AccountList
{
public:
    friend class Utility;
protected:
    std::vector<User> aList;
    Account aCurUser; // Moi lan su dung chi co 1 User
public:
    AccountList();
    bool loadUsers();
    bool loadCurUserInfo();
    bool saveUsers();
    bool saveCurUserInfo();
};
