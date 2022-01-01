#include "BorrowCard.h"

// Constructor and Destructor
BorrowCard::BorrowCard()
{
    this->bcAccountID = this->bcBarcode = this->bcID = this->bcISBN = "";
    Date _today;
    this->bcCreatedDate = this->bcDueDate = _today;
}

BorrowCard::BorrowCard(std::string ID, std::string accountID, std::string ISBN, std::string Barcode)
{
    this->bcID = ID;
    this->bcAccountID = accountID;
    this->bcISBN = ISBN;
    this->bcBarcode = Barcode;
    Date _today;
    this->bcCreatedDate = _today;
    this->bcDueDate = this->bcCreatedDate + 14;
}

// Operator overloading

// Member function
int BorrowCard::getDateDis()
{
    return this->bcDueDate - this->bcCreatedDate;
}

Date BorrowCard::getReturnDate()
{
    return this->bcDueDate;
}

Date BorrowCard::extendDate()
{
    this->bcDueDate = this->bcDueDate + 14;
}

std::string BorrowCard::getInfo()
{
    std::stringstream writer;
    writer << this->bcID
           << "," << this->bcAccountID
           << "," << this->bcISBN
           << "," << this->bcCreatedDate.toString()
           << "," << this->bcDueDate.toString();
    return writer.str();
}

std::string BorrowCard::toString() const
{
    std::stringstream writer;
    writer << this->bcID
           << "," << this->bcAccountID
           << "," << this->bcISBN
           << "," << this->bcBarcode
           << "," << this->bcCreatedDate.toString()
           << "," << this->bcDueDate.toString();
    return writer.str();
}