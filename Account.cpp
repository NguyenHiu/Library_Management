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
    aInfo.changeProfile(profile);
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

std::string Account::getUserName()
{
    return aUsername;
}

std::string Account::getPassword()
{
    return aPassword;
}

AccountStatus Account::getStatus()
{
    return aStatus;
}

void Account::updateUser(std::string us, std::string pw, ull id, AccountStatus status) {
    aUsername = us;
    aPassword = pw;
    aID = id;
    aStatus = status;
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