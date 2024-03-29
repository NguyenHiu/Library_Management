#include "BorrowCard.h"

// Constructor and Destructor
BorrowCard::BorrowCard()
{
    this->bcAccountID = this->bcBarcode = this->bcID = this->bcISBN = 0;
    Date _today;
    this->bcCreatedDate = this->bcDueDate = _today;
}

BorrowCard::BorrowCard(ull ID, ull accountID, ull ISBN, ull Barcode)
{
    this->bcID = ID;
    this->bcAccountID = accountID;
    this->bcISBN = ISBN;
    this->bcBarcode = Barcode;
    Date _today;
    this->bcCreatedDate = _today;
    this->bcDueDate = this->bcCreatedDate + DAYS_LIMIT;
}

BorrowCard::BorrowCard(std::vector<std::string> bcTokens)
{
    int i = -1;
    this->bcID = std::stoull(bcTokens[++i]);
    this->bcAccountID = std::stoull(bcTokens[++i]);
    this->bcISBN = std::stoull(bcTokens[++i]);
    this->bcBarcode = std::stoull(bcTokens[++i]);

    Date _today;

    Date *_created = Date::Parse(bcTokens[++i]);
    this->bcCreatedDate = _created != nullptr ? *_created : _today;

    Date *_due = Date::Parse(bcTokens[++i]);
    this->bcDueDate = _due != nullptr ? *_due : (this->bcCreatedDate + DAYS_LIMIT);

    delete _created;
    delete _due;
    _created = _due = nullptr;
}

// Operator overloading

// Member function
ull BorrowCard::getID()
{
    return this->bcID;
}

ull BorrowCard::getISBN()
{
    return this->bcISBN;
}

ull BorrowCard::getAccountID()
{
    return this->bcAccountID;
}

int BorrowCard::getDateDis()
{
    Date _today;
    return this->bcDueDate - _today;
}

Date BorrowCard::getReturnDate()
{
    return this->bcDueDate;
}

Date BorrowCard::extendDate()
{
    this->bcDueDate = this->bcDueDate + DAYS_EXTEND;
    return this->bcDueDate;
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

std::vector<std::string> BorrowCard::toMultipleString() const
{
    std::vector<std::string> res;
    res.push_back(std::to_string(this->bcID));
    res.push_back(std::to_string(this->bcAccountID));
    res.push_back(std::to_string(this->bcISBN));
    // res.push_back(this->bcCreatedDate.toString());
    res.push_back(this->bcDueDate.toString());
    return res;
}