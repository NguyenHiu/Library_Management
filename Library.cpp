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

void Library::insertBook(Book other)
{
    this->lBooks.push_back(other);
}

Book *Library::removeBook(ull _isbn)
{
    int pos = Utility::searchByISBN(*this, _isbn);
    if (pos >= 0)
    {
        Book *res = new Book(this->lBooks[pos]);
        this->lBooks.erase(this->lBooks.begin() + pos);
        return res;
    }
    return nullptr;
}

bool Library::changeBook(int _index, ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _pubDate)
{
    if (_index < 0 || _index >= this->lBooks.size())
        return false;
    this->lBooks[_index].changeInfo(_isbn, _title, _author, _publisher, _pubDate);
    return true;
}

void Library::upToDate()
{
    // Sort and create MetaData again
}

void Library::saveFile()
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
    }
}

// Friend function

// Class Utility

// Member function
int Utility::searchByISBN(Library lib, ull _isbn)
{
    int _size = lib.lBooks.size();
    int l = 0, r = _size - 1;
    while (l < r)
    {
        int pos = l + double((r - l) / double(lib.lBooks[r].bISBN - lib.lBooks[l].bISBN)) * (_isbn - lib.lBooks[l].bISBN);
        if (pos < 0 || pos >= _size)
            return -1;
        if (_isbn == lib.lBooks[pos].bISBN)
            return pos;
        else if (_isbn < lib.lBooks[pos].bISBN)
            r = pos - 1;
        else
            l = pos + 1;
    }
    return -1;
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
            int pos = Utility::searchByISBN(lib, res[j]);
            if (pos >= 0)
            {
                Book b = lib.lBooks[pos];
                if (std::find(result.begin(), result.end(), b) == result.end())
                {
                    result.push_back(b);
                }
            }
        }
    }
    return result;
}

int Utility::reportBooksQuantity(Library lib)
{
    int n = lib.lBooks.size();
    int total = n;
    for (int i = 0; i < n; ++i)
        total += lib.lBooks[i].bCopies.size();
    return total;
}