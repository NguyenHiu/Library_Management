#include "Librarian.h"

// Constructor and Destructor

// Operator overloading

// Member function
void Librarian::addBook(Book _book)
{
    // Find isbn
    this->lBooks.push_back(_book);
}

int Librarian::getTotalMembersByGender(bool _gender)
{
    int total = 0;
    int n = this->lPeople.size();
    for (int i = 0; i < n; ++i)
        if(this->lPeople[i].getGender() == _gender) ++total;
    return total;
}