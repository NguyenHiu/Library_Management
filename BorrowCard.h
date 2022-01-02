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
    BorrowCard(ull, ull, ull, ull);
    BorrowCard(std::vector<std::string>);

public:
    int getDateDis();
    Date getReturnDate();
    Date extendDate();
    std::string getInfo();
    std::string toString() const;
};
