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
    Date bBorrowed, bDueDate, bPubDate;
    BookStatus bStatus;

public:
    BookCopies(std::string _barCode, Date _pubDate);
    /* {
        bBarCode = _barCode;
        bPubDate = _pubDate;
        bStatus = Available;
    } */

public:
    bool checkOut();
    /* {
        if (bStatus == Available)
        {
            Date _today;
            bStatus = Loaned;
            bBorrowed = _today;
            bDueDate = bBorrowed + 7;
            return true;
        }
        return false;
    } */
};