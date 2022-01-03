#pragma once
//#include "DevLibraries.h"
#include "Person.h"
//#include "Library.h"

enum AccountStatus
{
    Active,
    Canceled
};

class Account
{
private:
    std::string aID, aUsername, aPassword;
    AccountStatus aStatus;
    Person aInfo;
    std::vector<std::string> aBooksBorrowed;
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
    Person getInfo();
    void updateInfo(Person info);
    void updateUser(std::string us, std::string pw, std::string id, AccountStatus status) {
        aUsername = us;
        aPassword = pw;
        aID = id;
        aStatus = status;
    }
    std::string getID() {return aID;}
};