#pragma once
#include "DevLibraries.h"
#include "Book.h"
#include "Person.h"
#include "BorrowCard.h"

class Library
{
public:
    friend class Utility;

private:
    std::vector<Book> lBooks;
    std::vector<Person> lPerson;
    std::vector<BorrowCard> lBCards;
    // ISBN increasing
    std::unordered_map<std::string, std::vector<ull>> lMetaData;

public:
    ull checkISBN(std::string _isbn);
    bool loadBooks();
    void insertBook(Book other);
    Book *removeBook(ull _isbn);
    bool changeBook(int _index, ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _pubDate);
    void createSearchData();
    bool loadPerson(); // Not yet
    void upToDate(); // Not yet
    void saveFile();
};

class Utility
{
public:
    static int searchByISBN(Library lib, ull _isbn);
    static std::vector<Book> searchByTitle(Library lib, std::string query);
    static int reportBooksQuantity(Library lib);
    static int reportMembersQuantity(Library lib);               // Not yet
    static std::vector<Book> reportBooksLoaned(Library lib);     // Not yet
    static std::vector<Person> reportPeopleOverdue(Library lib); // Not yet
};