#include "Book.h"

// Constructor and Destructor
Book::Book()
{
    this->bISBN = 0;
    this->bAuthor = this->bTitle = this->bPublisher = "";
    Date _today;
    this->bPubDate = _today;
}

Book::Book(std::vector<std::string> bTokens)
{
    int i = -1, n = bTokens.size();
    this->bISBN = stoull(bTokens[++i]);
    this->bTitle = bTokens[++i];
    this->bAuthor = bTokens[++i];
    this->bPublisher = bTokens[++i];
    Date *bPubDate = Date::Parse(bTokens[++i]);
    if (bPubDate)
    {
        this->bPubDate = *bPubDate;
        delete bPubDate;
        bPubDate = nullptr;
    }
    else
    {
        Date _today;
        this->bPubDate = _today;
    }
    while (++i < n - 1)
    {
        std::string barCode = bTokens[i];
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
void Book::changeInfo(ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _bPubDate)
{
    this->bISBN = _isbn;
    this->bTitle = _title;
    this->bAuthor = _author;
    this->bPublisher = _publisher;
    Date *publishDate = Date::Parse(_bPubDate);
    if (publishDate != nullptr)
    {
        this->bPubDate = *publishDate;
        delete publishDate;
        publishDate = nullptr;
    }
}

std::string Book::toString() const
{
    std::stringstream writer;
    writer << this->bISBN << "," 
           << this->bTitle << "," 
           << this->bAuthor << "," 
           << this->bPublisher << "," 
           << this->bPubDate.toString() << ","; 
    for (auto i : bCopies) writer << i.toString() << ",";
    return writer.str();
}

std::string Book::checkOut()
{
    int n = this->bCopies.size();
    for (int i = 0; i < n; ++i)
        if (bCopies[i].checkOut() == true)
            return bCopies[i].toString();
    return "";
}

ull Book::getID()
{
    return this->bISBN;
}

int Book::getCopiesQuantity()
{
    return this->bCopies.size();
}

std::string Book::getTitle()
{
    return this->bTitle;
}

// Friend function
