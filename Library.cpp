#include "Library.h"

// Constructor and Destructor

// Operator Overloading

// Member function
void Library::createSearchData()
{
    for (int i = this->lBooks.size() - 1; i >= 0; --i)
    {
        std::vector<std::string> tokens = Data::removeStopWord(Data::dStopwords, this->lBooks[i].bTitle);
        for (int j = tokens.size() - 1; j >= 0; --j)
        {
            if (this->lMetaData.find(tokens[j]) == this->lMetaData.end())
            {
                this->lMetaData.insert(std::make_pair(tokens[j], std::vector<ull>()));
            }
            this->lMetaData[tokens[j]].push_back(this->lBooks[i].bISBN);
        }
    }
}

// Function updates MetaData again after insertion and removal
void Library::upToDate()
{
    this->createSearchData();
}

ull Library::checkISBN(std::string _isbn)
{
    if (_isbn.length() != 10)
        return 0;
    std::regex reg("\\d{10}");
    std::smatch match;
    std::string ISBN = "";
    if (std::regex_search(_isbn, match, reg))
    {
        ISBN = match.str(0);
        int s = 0, t = 0;
        for (int i = 0; i < 10; ++i)
        {
            t += ISBN[i] - '0';
            s += t;
        }
        return s % 11 != 0 ? stoull(ISBN) : 0;
    }
    return 0;
}

bool Library::loadBooks()
{
    //-----------------------------------------------------------------
    // Books.csv Format                                               |
    // ull, string, string, string, Date, ull, ull, ...               |
    // ISBN, Title, Author, Publisher, PubDate, Barcode1, Barcode2 ...|
    //-----------------------------------------------------------------
    std::ifstream fi(BOOKS);
    if (fi.is_open())
    {
        std::string line = "";
        // std::getline(fi, line); // Remove header of CSV
        while (!fi.eof())
        {
            std::getline(fi, line);
            std::vector<std::string> tokens = Tokenizer::Parse(line, ",");
            Book b(tokens);
            this->lBooks.push_back(b);
        }
        fi.close();
        return true;
    }
    return false;
}

bool Library::loadBorrowCards()
{
    //-----------------------------------------------------
    // BorrowCards.csv Format                             |
    // ull, ull, ull, ull, Date, Date                     |
    // ID, AccountID, ISBN, Barcode, CreatedDate, DueDate |
    //-----------------------------------------------------
    std::ifstream fi(BOOKS);
    if (fi.is_open())
    {
        std::string line = "";
        // std::getline(fi, line); // Remove header of CSV
        while (!fi.eof())
        {
            std::getline(fi, line);
            std::vector<std::string> tokens = Tokenizer::Parse(line, ",");
            BorrowCard bc(tokens);
            this->lBCards.push_back(bc);
        }
        fi.close();
        return true;
    }
    return false;
}

bool Library::loadPeople()
{
    //----------------------------------------------------------
    // People.csv Format                                       |
    // string, string, string, Date, string, string, bool      |
    // Name, Email, Phone, DayOfBirth, IDCard, Address, Gender |
    //----------------------------------------------------------
    std::ifstream fi(PEOPLE);
    if (fi.is_open())
    {
        std::string line = "";
        // std::getline(fi, line); // Remove header of CSV
        while (!fi.eof())
        {
            std::getline(fi, line);
            std::vector<std::string> tokens = Tokenizer::Parse(line, ",");
            Person p(tokens);
            this->lPeople.push_back(p);
        }
        fi.close();
        return true;
    }
    return false;
}

bool Library::saveBooks()
{
    std::ofstream fo(BOOKS);
    if (fo.is_open())
    {
        int n = this->lBooks.size();
        for (int i = 0; i < n - 1; ++i)
        {
            fo << this->lBooks[i].toString() << std::endl;
        }
        fo << this->lBooks[n - 1].toString();
        fo.close();
        return true;
    }
    return false;
}

bool Library::saveBorrowCards()
{
    std::ofstream fo(BORROWCARDS);
    if (fo.is_open())
    {
        int n = this->lBCards.size();
        for (int i = 0; i < n - 1; ++i)
        {
            fo << this->lBCards[i].toString() << std::endl;
        }
        fo << this->lBCards[n - 1].toString();
        fo.close();
        return true;
    }
    return false;
}

bool Library::savePeople()
{
    std::ofstream fo(PEOPLE);
    if (fo.is_open())
    {
        int n = this->lPeople.size();
        for (int i = 0; i < n - 1; ++i)
        {
            fo << this->lPeople[i].toString() << std::endl;
        }
        fo << this->lPeople[n - 1].toString();
        fo.close();
        return true;
    }
    return false;
}

// Friend function

// support functions:

// find the appropriate position for book
int Library::shouldPutBookHere(ull _isbn)
{
    int size = lBooks.size(), l = 0, r = size - 1;
    int pos;
    while (l < r)
    {
        pos = l + double((r - l) / double(lBooks[r].getISBN() - lBooks[l].getISBN())) * (_isbn - lBooks[l].getISBN());
        if (pos < 0)
            return 0;
        if (pos >= size)
            return size;
        if (_isbn == lBooks[pos].getISBN())
            return -1;
        if (l + 1 == r)
            return l;
        if (_isbn < lBooks[pos].getISBN())
            r = pos - 1;
        else
            l = pos + 1;
    }
    return l;
}

// find position of book in lBooks with isbn
int Library::findBookPos(ull _isbn)
{
    int size = lBooks.size(), l = 0, r = size - 1;
    int pos;
    while (l < r)
    {
        pos = l + double((r - l) / double(lBooks[r].getISBN() - lBooks[l].getISBN())) * (_isbn - lBooks[l].getISBN());
        if (pos < 0 || pos >= size)
            return -1;
        if (_isbn == lBooks[pos].getISBN())
            return pos;
        if (l + 1 == r)
            return l;
        if (_isbn < lBooks[pos].getISBN())
            r = pos - 1;
        else
            l = pos + 1;
    }
    return -1;
}