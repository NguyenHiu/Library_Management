#include "BookCopies.h"

// Constructor and Destructor
BookCopies::BookCopies(std::string _barCode, Date _pubDate)
{
    this->bBarCode = _barCode;
    this->bPubDate = _pubDate;
    this->bStatus = Available;
}

// Member function
bool BookCopies::checkOut()
{
    if (this->bStatus == Available)
    {
        Date _today;
        this->bStatus = Loaned;
        this->bBorrowed = _today;
        this->bDueDate = bBorrowed + 7;
        return true;
    }
    return false;
}