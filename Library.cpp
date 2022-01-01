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

void Library::upToDate()
{
    // Sort, update MetaData again
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
            lBooks.push_back(b);
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
        for (int i = this->lBooks.size() - 1; i > 0; --i)
        {
            fo << this->lBooks[i].toString() << std::endl;
        }
        fo << this->lBooks[0].toString();
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
    int size = lBooks.size(), l = 0, r = size-1;
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
        if (l+1 == r)
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
    int size = lBooks.size(), l = 0, r = size-1;
    int pos;
    while (l < r)
    {
        pos = l + double((r - l) / double(lBooks[r].getISBN() - lBooks[l].getISBN())) * (_isbn - lBooks[l].getISBN());
        if (pos < 0 || pos >= size)
            return -1;
        if (_isbn == lBooks[pos].getISBN())
            return pos;
        if (l+1 == r)
            return l;
        if (_isbn < lBooks[pos].getISBN())
            r = pos - 1;
        else
            l = pos + 1;
    }
    return -1;
}