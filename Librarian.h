#pragma once
//#include "DevLibraries.h"
//#include "Date.h"
//#include "Library.h"
#include "Account.h"

class Librarian : public Account {
public:
    Librarian()
    {
        std::cout << "Librarian\n";
    }
    /*bool addBookItem(Library _lib, std::string _isbn, std::string _title, std::string _publisher, std::string _language, std::string _pages)
    {
    }*/
};