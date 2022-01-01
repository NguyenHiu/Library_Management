#include "Librarian.h"

// Constructor and Destructor

// Operator overloading

// Member function

// Only remove accoount in vector<Person> of Library
// T.H: Remove User in vector<User> of AccountList?
void Librarian::removeAccount(std::string username)
{
    // Remove User in AccountList
    for (int i = 0; i < aList.size(); i++)
        if (aList[i].isThisUser(username))
        {
            aList.erase(aList.begin()+i);
            break;
        }

    // Remove Person in Library
    for (int i = 0; i < lPeople.size(); i++)
        if (lPeople[i].isThisPerson(username))
        {
            lPeople.erase(lPeople.begin()+i);
            break;
        }
}

void Librarian::addBook(Book book)
{
    // Same idea with searchISBN
    int pos = shouldPutBookHere(book.getISBN());
    
    if (pos == -1)
        return; // Trung ISBN --> Khong them duoc
    if (pos == lBooks.size())
        lBooks.push_back(book);
    else
        lBooks.insert(lBooks.begin()+pos, book);
}

bool Librarian::removeBook(ull isbn)
{
    int pos = findBookPos(isbn);
    if (pos == -1)
        return false;
    
    // Dang lam ...

    return true;
}




