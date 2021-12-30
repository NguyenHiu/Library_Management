#pragma once
#include "DevLibraries.h"
#include "Date.h"

enum BookStatus
{
    Available,
    Reserved,
    Loaned
};

class BookCopies
{
private:
    std::string bBarCode;
    Date bBorrowed, bDueDate;
    BookStatus bStatus;

public:
    BookCopies(std::string _barCode);

public:
    bool checkOut();
    std::string toString() const;
};