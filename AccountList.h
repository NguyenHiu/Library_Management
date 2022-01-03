#pragma once
//#include "Utility.h"
#include "Account.h"

class User
{
public:
    std::string user, pass;
    ull ID;
    AccountStatus status;
public:
    User(std::string us, std::string pw, ull id, AccountStatus _status) {
        user = us;
        pass = pw;
        ID = id;
        status = _status;
    }
    User(std::vector<std::string> info) {
        ID = stoull(info[0]); 
        user = info[1];
        pass = info[2];
        status = (info[3] == "Active" ? AccountStatus::Active : AccountStatus::Canceled);
    }
    bool isThisUser(std::string username) {
        return (username == user);
    }
    
    // test
    void changePass(std::string nPass) {
        pass = nPass;
    }
    std::string toString() {
        std::stringstream s;
        s << ID << "," << user << ","
          << pass << "," 
          << (status == Active ? "Active" : "Canceled") << ",";
        return s.str();
    }
    //
};

class AccountList
{
public:
    friend class Utility;
protected:
    std::vector<User> aList; // sorted by username
    Account aCurUser; // Moi lan su dung chi co 1 User
public:
    AccountList();
    bool loadUsers();
    bool loadCurUserInfo();
    bool changeCurUser(std::string us); // To swith account 
    
    bool saveUsers();
    bool saveCurUserInfo();
    
    // test
    void printUSERs()
    {
        for (auto i : aList)
            std::cout << i.toString() << "\n";
    }
    void showCurUser() 
    {
        std::cout << aCurUser.toString() << "\n";
    }

    void changeCurPass(std::string nPass)
    {
        aCurUser.changePass(nPass);
        for (int i = 0; i < aList.size(); i++)
            if (aList[i].ID == aCurUser.getID())
            {
                std::cout << " - Before- aCurUser_change: " << aList[i].toString() << "\n";
                aList[i].changePass(nPass);
                std::cout << " - After- aCurUser_change: " << aList[i].toString() << "\n";
                break;
            }
        std::cout << "* aList after change:\n";
        this->printUSERs();
    }

    //
};
