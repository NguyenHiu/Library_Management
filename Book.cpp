#include "Book.h"

// Constructor and Destructor
Book::Book(std::vector<std::string> bTokens)
{
    int i = -1, n = bTokens.size();
    this->bISBN = stoull(bTokens[++i]);
    this->bTitle = bTokens[++i];
    this->bAuthor = bTokens[++i];
    this->bPublisher = bTokens[++i];
    Date *pubDate = Date::Parse(bTokens[++i]);
    if (pubDate)
    {
        this->pubDate = *pubDate;
        delete pubDate;
        pubDate = nullptr;
    }
    else
    {
        Date _today;
        this->pubDate = _today;
    }
    while (i < n - 1)
    {
        std::string barCode = bTokens[++i];
        BookCopies copies(barCode);
        this->bCopies.push_back(copies);
    }
}

// Operator Overloading
bool Book::operator==(const Book &other) const
{
    return (this->bISBN == other.bISBN);
}

// Member function
void Book::changeInfo(ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _pubDate)
{
    this->bISBN = _isbn;
    this->bTitle = _title;
    this->bAuthor = _author;
    this->bPublisher = _publisher;
    Date *publishDate = Date::Parse(_pubDate);
    if (publishDate != nullptr)
    {
        this->pubDate = *publishDate;
        delete publishDate;
        publishDate = nullptr;
    }
}

std::string Book::toString() const
{
    std::stringstream writer;
    writer << this->bISBN << ","<< this->bTitle << "," << this->bAuthor << "," << this->bPublisher << "," << this->pubDate.toString();
    for (int i = this->bCopies.size() - 1; i >= 0; --i)
        writer << "," << this->bCopies[i].toString();
    return writer.str();
}

// Friend function
