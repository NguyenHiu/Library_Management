#pragma once
#include "Utility.h"
#include "Account.h"
#include <fstream>
#include <iostream>

// Class User nay theo UML thi thuoc tinh la private
// Nhung T.H nghi la moi AccountList co User, ma chi co Librarian moi tac dong duoc AccountList
// Nen cho public de khoi can get/set
class User
{
public:
    friend class Utility; 
    // Tai sao lai friend voi Utility?
public:
    std::string user, pass;
    AccountStatus status;
public:
    User(std::string us, std::string pw) {
        user = us;
        pass = pw;
    }
};

class AccountList
{
private:
    std::vector<User> aList;
    Account aCurUser; // Moi lan su dung chi co 1 User
public:
    AccountList();
    bool loadUsers();
    bool loadCurUserInfo();
    bool saveUsers();
    bool saveCurUserInfo();
};
