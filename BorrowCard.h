#pragma once
#include "DevLibraries.h"
#include "Date.h"

class BorrowCard
{
private:
    ull bcID, bcAccountID, bcISBN, bcBarcode;
    Date bcCreatedDate, bcDueDate;

public:
    BorrowCard();
    BorrowCard(ull ID, ull accID, ull ISBN, ull Barcode);
    BorrowCard(std::vector<std::string> bcTokens);

public:
    ull getID();
    ull getISBN();
    int getDateDis();
    Date getReturnDate();
    Date extendDate();
    std::string getInfo();
    std::vector<std::string> toMultipleString() const;
    std::string toString() const;
};
