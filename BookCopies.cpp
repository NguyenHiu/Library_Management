#include "BookCopies.h"

// Constructor and Destructor
BookCopies::BookCopies(std::string _barCode)
{
    this->bBarCode = _barCode;
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
        this->bDueDate = this->bBorrowed + 7;
        return true;
    }
    return false;
}

std::string BookCopies::toString() const
{
    std::stringstream writer;
    writer << this->bBarCode;
    return writer.str();
}