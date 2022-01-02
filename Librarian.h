#pragma once
#include "DevLibraries.h"
#include "Date.h"
#include "Library.h"
#include "Account.h"
#include "AccountList.h"

enum ReturnStatus
{
    Late,
    Early,
    OnTime
};

class Librarian : public Account, public Library, public AccountList
{
public:
    void removeAccount(std::string username);
    void addBook(Book book);
    bool removeBook(ull isbn);
    bool modifyBook(std::vector<std::string> tokens);
    std::string lookUpMemberByName(std::string name);
    std::string lookUpMemberByIDCard(std::string id);
    std::string lookUpBorrowCard(std::string id);
    std::vector<std::string> getMembers();
    std::vector<std::string> getBooksLoaned();
    std::vector<std::string> getMembersOverdue();
    std::vector<std::string> getMemberByGender(bool gender);
    std::string createBorrowCard(std::string isbn);
    ReturnStatus removeBorrowCard(std::string barcode);
    
    /* Book *Library::removeBook(ull _isbn)
{
    int pos = Utility::searchByISBN(*this, _isbn);
    if (pos >= 0)
    {
        Book *res = new Book(this->lBooks[pos]);
        this->lBooks.erase(this->lBooks.begin() + pos);
        return res;
    }
    return nullptr; */
};