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
    BookStatus bStatus;

public:
    BookCopies();
    BookCopies(std::string _barCode);

public:
    bool checkOut();
    std::string toString() const;
};