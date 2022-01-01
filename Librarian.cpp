#include "Librarian.h"

// Constructor and Destructor

// Operator overloading

// Member function

// Only remove accoount in vector<Person> of Library
void Librarian::removeAccount(std::string username)
{
    /*for (int i = 0; i < aList.size(); i++)
    {
        if (aList[i].user == username)
            aList.erase(aList.begin()+i);
    }*/
}

void Librarian::addBook(Book _book)
{
    // Find isbn
    this->lBooks.push_back(_book);
}