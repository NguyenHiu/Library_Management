#include "Book.h"

// Constructor and Destructor
Book::Book(std::vector<std::string> bTokens)
{
    int i = 0, n = bTokens.size();
    this->bISBN = stoull(bTokens[i++]);
    this->bTitle = bTokens[i++];
    this->bAuthor = bTokens[i++];
    this->bPublisher = bTokens[i++];
    while (i < n)
    {
        std::string barCode = bTokens[i++];
        Date *pubDate = Date::Parse(bTokens[i++]);
        if (pubDate)
        {
            BookCopies copies(barCode, *pubDate);
            this->bCopies.push_back(copies);
        }
    }
}

// Operator Overloading
bool Book::operator==(const Book &other) const
{
    return (this->bISBN == other.bISBN);
}

// Member function

// Friend function
std::ostream &operator<<(std::ostream &os, const Book &b)
{
    os << "ISBN: " << b.bISBN << std::endl
       << "Name: " << b.bTitle << std::endl
       << "Author: " << b.bAuthor << std::endl
       << "Publisher: " << b.bPublisher;
    return os;
}