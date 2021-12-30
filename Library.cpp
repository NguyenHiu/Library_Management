#include "Library.h"

// Class Library

// Constructor and Destructor

// Operator Overloading

// Member function
bool Library::loadBooks()
{
    std::ifstream fi(BOOKS);
    if (fi.is_open())
    {
        std::string line = "";
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

// Friend function

// Class Utility

// Member function
Book *Utility::searchByISBN(Library lib, ull _isbn)
{
    int l = 0, r = lib.lBooks.size() - 1;
    while (l < r)
    {
        int pos = l + double((r - l) / double(lib.lBooks[r].bISBN - lib.lBooks[l].bISBN)) * (_isbn - lib.lBooks[l].bISBN);
        if (pos < 0 || pos >= lib.lBooks.size())
            return nullptr;
        if (_isbn == lib.lBooks[pos].bISBN)
            return new Book(lib.lBooks[pos]);
        else if (_isbn < lib.lBooks[pos].bISBN)
            r = pos - 1;
        else
            l = pos + 1;
    }
    return nullptr;
}

std::vector<Book> Utility::searchByTitle(Library lib, std::string query)
{
    std::vector<Book> result;
    std::vector<std::string> tokens = Data::removeStopWord(Data::dStopwords, query);
    for (int i = tokens.size() - 1; i >= 0; --i)
    {
        std::vector<ull> res = lib.lMetaData[tokens[i]];
        for (int j = res.size() - 1; j >= 0; --j)
        {
            Book *b = Utility::searchByISBN(lib, res[j]);
            if (b != nullptr && std::find(result.begin(), result.end(), *b) == result.end())
            {
                result.push_back(*b);
                delete b;
                b = nullptr;
            }
        }
    }
    return result;
}