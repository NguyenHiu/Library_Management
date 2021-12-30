#pragma once
#include "DevLibraries.h"
#include "Book.h"
#include "Person.h"

class Library
{
public:
    friend class Utility;

private:
    std::vector<Book> lBooks;
    std::vector<Person> lPerson;
    // ISBN increasing
    std::unordered_map<std::string, std::vector<ull>> lMetaData;

public:
    bool loadBooks();
    /* {
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
    } */

    void createSearchData();
    /* {
        for (int i = lBooks.size() - 1; i >= 0; --i)
        {
            std::vector<std::string> tokens = Data::removeStopWord(Data::dStopwords, lBooks[i].bTitle);
            for (int j = tokens.size() - 1; j >= 0; --j)
            {
                if (lMetaData.find(tokens[j]) == lMetaData.end())
                {
                    lMetaData.insert(std::make_pair(tokens[j], std::vector<ull>()));
                }
                lMetaData[tokens[j]].push_back(lBooks[i].bISBN);
            }
        }
    } */
    bool loadPerson();
};

class Utility
{
public:
    static Book *searchByISBN(Library lib, ull _isbn);
    /* {
        int l = 0, r = lib.lBooks.size() - 1;
        while (l < r)
        {
            int pos = l + double((r - l) / double(lib.lBooks[r].bISBN - lib.lBooks[l].bISBN)) * (_isbn - lib.lBooks[l].bISBN);
            if (_isbn == lib.lBooks[pos].bISBN)
                return new Book(lib.lBooks[pos]);
            else if (_isbn < lib.lBooks[pos].bISBN)
                r = pos - 1;
            else
                l = pos + 1;
        }
        return nullptr;
    } */

    /* static Book *searchByISBN(Library lib, std::string query)
    {
        int l = 0, r = lib.lBooks.size() - 1;
        ull x = std::stoull(query);
        while (l < r)
        {
            int pos = l + double((r - l) / double(lib.lBooks[r].bISBN - lib.lBooks[l].bISBN)) * (x - lib.lBooks[l].bISBN);
            if (x == lib.lBooks[pos].bISBN)
                return new Book(lib.lBooks[pos]);
            else if (x < lib.lBooks[pos].bISBN)
                r = pos - 1;
            else
                l = pos + 1;
        }
        return nullptr;
    } */

    static std::vector<Book> searchByTitle(Library lib, std::string query);
    /* {
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
                    std::cout << "Get one!" << std::endl;
                    result.push_back(*b);
                    delete b;
                    b = nullptr;
                }
            }
        }
        return result;
    } */
};