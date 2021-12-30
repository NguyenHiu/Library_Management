#include "BookCopies.h"

// Constructor and Destructor
BookCopies::BookCopies()
{
    this->bBarCode = "";
    this->bStatus = Available;
}
BookCopies::BookCopies(std::string _barCode)
{
    this->bBarCode = _barCode;
    this->bStatus = Available;
}

// Member function
bool BookCopies::checkOut()
{
    if (this->bStatus != Loaned)
    {
        this->bStatus = Loaned;
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