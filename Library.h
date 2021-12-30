#pragma once
#include "DevLibraries.h"
#include "Book.h"
#include "Person.h"
#include "BorrowCard.h"
#include "Utility.h"

class Library
{
public:
    friend class Utility;

protected:
    std::vector<Book> lBooks;
    std::vector<Person> lPeople;
    std::vector<BorrowCard> lBCards;

    // ISBN increasing
    std::unordered_map<std::string, std::vector<ull>> lMetaData;

public:
    ull checkISBN(std::string _isbn);
    bool loadBooks();
    bool loadPeople(); // Not yet
    bool loadBorrowCards(); // Not yet
    bool savePeople(); // Not yet
    bool saveBooks(); // Not yet
    bool saveBorrowCards(); // Not yet

public:
    void createSearchData();
    void upToDate(); // Not yet
};