#pragma once
#include "DevLibraries.h"
//#include "Date.h"
#include "Library.h"
#include "Account.h"

enum ReturnStatus
{
    Late,
    Early,
    OnTime
};

class Librarian : public Account, public Library
{
public:
    void removeAccount(std::string username);
    void addBook(Book _book);
    bool removeBook(ull _isbn);
    bool modifyBook(std::vector<std::string> _tokens);
    std::string lookUpMemberByName(std::string _name);
    std::string lookUpMemberByIDCard(std::string _id);
    std::string lookUpBorrowCard(std::string _id);
    std::vector<std::string> getMembers();
    std::vector<std::string> getBooksLoaned();
    std::vector<std::string> getMembersOverdue();
    int getTotalMembersByGender(bool _gender);
    std::string createBorrowCard(std::string _isbn);
    ReturnStatus removeBorrowCard(std::string _barcode);
    
    /*bool addBookItem(Library _lib, std::string _isbn, std::string _title, std::string _publisher, std::string _language, std::string _pages)
    {
    }*/
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