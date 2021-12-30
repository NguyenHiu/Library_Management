#pragma once
#include "DevLibraries.h"
#include "Date.h"

class BorrowCard
{
private:
    std::string bcID, bcAccountID, bcISBN, bcBarcode;
    Date bcCreatedDate, bcDueDate;

public:
    BorrowCard();
    BorrowCard(std::string, std::string, std::string, std::string);

public:
    int getDateDis();
    Date getReturnDate();
    Date extendDate();
    std::string getInfo();
    std::string toString() const;
};
