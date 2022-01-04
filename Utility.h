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
    static int enterLogin(User, AccountList&);

    // vector: Id, Username, Password, Status, Email, Phone, ID Card, Address, Gender, Day of Birth
    static int enterRegister(Library&, AccountList&, std::vector<std::string>);

    static bool enterLogOut(); // Thoat ra giao dien chinh
};