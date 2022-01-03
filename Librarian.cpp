#include "Librarian.h"

// Constructor and Destructor

// Operator overloading

// Member function

// Done
bool Librarian::removeAccount(std::string username)
{
    // Remove User in AccountList
    int n = this->aList.size();
    for (int i = 0; i < n; ++i)
        if (this->aList[i].isThisUser(username))
        {
            aList.erase(aList.begin() + i);
            return true;
        }

    return false;

    /*
    // Remove Person in Library
    n = this->lPeople.size();
    for (int i = 0; i < n; i++)
        if (lPeople[i].isThisPerson(username))
        {
            lPeople.erase(lPeople.begin() + i);
            break;
        }
    */
}

// Done
bool Librarian::addBook(Book book)
{
    int pos = this->getBookIndexToInsert(book.getID());

    // Case 1: Available
    if (pos == -1)
        return false;

    // Case 2: Not Available
    if (pos == this->lBooks.size())
        lBooks.push_back(book);
    else
        lBooks.insert(lBooks.begin() + pos, book);

    return true;
}

// Done
bool Librarian::removeBook(ull _isbn)
{
    int pos = Utility::searchByISBN(*this, _isbn);
    // Case 1: Not available
    if (pos == -1)
        return false;

    // Case 2: Available
    // Check if anyone borrow this book
    int n = this->lBCards.size();
    for (int i = 0; i < n; ++i)
        if (this->lBCards[i].getISBN() == _isbn)
            return false;

    // Remove that Book
    this->lBooks.erase(this->lBooks.begin() + pos);

    return true;
}

// Done
bool Librarian::modifyBook(std::vector<std::string> tokens)
{
    ull _isbn = stoull(tokens[0]);
    int pos = Utility::searchByISBN(*this, _isbn);
    // 6 vi co 1 string cuoi = "";
    if (pos == -1 || tokens.size() != 6)
        return false;
        
    this->lBooks[pos].changeInfo(_isbn, tokens[1], tokens[2], tokens[3], tokens[4]);
    return true;
}

// Done
std::string Librarian::lookUpMemberByName(std::string _name)
{
    ull id = -1;
    int l = 0, r = aList.size()-1, pos;
    while (l <= r)
    {
        pos = l + (r-l)/2;
        if (aList[pos].isThisUser(_name))
        {
            id = aList[pos].ID;
            break;
        }
        if (_name.compare(aList[pos].user) > 0)
            l = pos + 1;
        else
            r = pos - 1;
    }
    
    if (id == -1)
        return "";
    
    return lPeople[id-1].toString();
}

// Done
std::string Librarian::lookUpMemberByIDCard(std::string _idc)
{
    for (auto i : lPeople)
        if (i.isThisPersonIDC(_idc))
            return i.toString();    
    return "";
}

std::string Librarian::lookUpBorrowCard(ull _id)
{
    int pos = this->getBCIndexToRemove(_id);

    // Case: Cannot find out
    if (pos == -1)
        return "";

    return this->lBCards[pos].getInfo();
}

// Done
std::vector<std::string> Librarian::getMembers()
{
    std::vector<std::string> res;

    int n = this->lPeople.size();

    for (int i = 0; i < n; ++i)
        res.push_back(this->lPeople[i].toString());

    return res;
}

std::vector<std::string> Librarian::getBooksLoaned()
{
    std::vector<std::string> res;

    int n = this->lBCards.size();

    for (int i = 0; i < n; ++i)
    {
        // ID - Account ID - ISBN - ReturnedDate
        std::vector<std::string> _info = this->lBCards[i].toMultipleString();

        // In order to get Borrower's Name
        int posPerson = std::stoi(_info[1]);

        // In order to get Book's Title
        ull _isbn = std::stoull(_info[2]);
        int posBook = Utility::searchByISBN(*this, _isbn);

        // Combined to string
        // Format: ID - Title - Name - Returned Date
        res.push_back(_info[0] + "," + this->lBooks[posBook].getTitle() + "," + this->lPeople[posPerson].getName() + "," + _info[3]);
    }
    return res;
}

std::vector<std::string> Librarian::getMembersOverdue()
{
    int n = this->lBCards.size();

    std::vector<std::string> res;

    for (int i = 0; i < n; ++i)
    {
        int dateDis = this->lBCards[i].getDateDis();
        if (dateDis <= 0)
        {
            // ID - Account ID - ISBN - ReturnedDate
            std::vector<std::string> _info = this->lBCards[i].toMultipleString();

            // In order to get Borrower's Name
            int posPerson = std::stoi(_info[1]);

            // In order to get Book's Title
            ull _isbn = std::stoull(_info[2]);
            int posBook = Utility::searchByISBN(*this, _isbn);

            // Combined to string
            // Format: Title - Person - Contact - Returned Date - The number of days overdue
            res.push_back(this->lBooks[posBook].getTitle() + "," + this->lPeople[posPerson].getContactInfo() + "," + _info[3] + "," + std::to_string(-dateDis));
        }
    }

    return res;
}

std::vector<std::string> Librarian::getMemberByGender(bool gender)
{
    std::vector<std::string> res;
    int n = this->lPeople.size();
    for (int i = 0; i < n; ++i)
        if (this->lPeople[i].hasGender(gender))
            res.push_back(this->lPeople[i].toString());
    return res;
}

std::string Librarian::createBorrowCard(ull _isbn)
{
    int pos = Utility::searchByISBN(*this, _isbn);
    std::string barCode = this->lBooks[pos].checkOut();
    if (pos != 1 && barCode != "")
    {
        BorrowCard bc(this->lBCards.size(), this->aCurUser.getID(), _isbn, std::stoull(barCode));
        this->lBCards.push_back(bc);
        return bc.toString();
    }
    return "";
}

ull Librarian::removeBorrowCard(ull _bcID)
{
    int pos = this->getBCIndexToRemove(_bcID);
    int dateDis = 0;
    if (pos != -1)
    {
        dateDis = this->lBCards[pos].getDateDis();
        this->lBCards.erase(this->lBCards.begin() + pos);
    }

    if (dateDis == 0 || dateDis > 0)
        return 0;

    return abs(dateDis) * TEN_THOUSAND_D;
}