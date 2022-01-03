#pragma once
#include "DevLibraries.h"
#include "Book.h"
#include "Person.h"
#include "BorrowCard.h"

class Library
{
public:
    friend class Utility;

protected:
    std::vector<Book> lBooks;
    std::vector<Person> lPeople;
    std::vector<BorrowCard> lBCards;

private:
    // ISBN increasing
    std::unordered_map<std::string, std::vector<ull>> lMetaData;

protected:
    int getBookIndexToInsert(ull isbn); // For book
    int getBCIndexToRemove(ull bcID); // For BorrowCard
    int findBookPos(ull isbn);

public:
    ull checkISBN(std::string _isbn);
    bool loadBooks(); //
    bool loadPeople(); //
    bool loadBorrowCards();
    bool savePeople();
    bool saveBooks();
    bool saveBorrowCards();

public:
    void createSearchData();
    void upToDate();

    //test functions:
    void printBooks();
};