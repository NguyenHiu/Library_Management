#include "Account.h"

Account::Account()
{
    aID = -1;
    aUsername = "";
    aPassword = "";
    aInfo = Person();
    aStatus = Active;
}

Account::Account(ull ID, std::string US, std::string Pass, Person info)
{
    aID = ID;
    aUsername = US;
    aPassword = Pass;
    aInfo = info;
    aStatus = Active;
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
    return true;
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
    std::stringstream os;
    os << " - ID: " << aID << "\n"
       << " - Username: " << aUsername << "\n"
       << " - Passowrd: " << aPassword << "\n"
       << " - Info: " << "\n" << aInfo.toString() << "\n"
       << " - Status: " << (aStatus == Active ? "Active" : "Canceled") << "\n"; 
    return os.str();
}

std::string Account::getUserName()
{
    return aUsername;
}

void Account::updateInfo(Person info)
{
    aInfo = info;
}

Person Account::getInfo()
{
    return aInfo;
}

ull Account::getID()
{
    return aID;
}