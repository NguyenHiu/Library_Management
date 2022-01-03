#pragma once
#include "Library.h"
#include "AccountList.h"
#include "DevLibraries.h"

class Utility
{
public:
    static int searchByISBN(Library lib, ull _isbn);
    static std::vector<Book> searchByTitle(Library lib, std::string query);
    static std::vector<std::string> displayBooks(Library lib);
    static int getBooksQuantity(Library lib);
    // static bool enterLogin(User, AccountList&);
    // static bool enterRegister(Library&, AccountList&, Account): bool
    // static bool enterLogOut(AccountList, string, string): bool
};