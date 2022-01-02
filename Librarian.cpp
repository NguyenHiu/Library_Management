#include "Librarian.h"

// Constructor and Destructor

// Operator overloading

// Member function

// Only remove accoount in vector<Person> of Library
// T.H: Remove User in vector<User> of AccountList?
bool Librarian::removeAccount(std::string username)
{
    // Remove User in AccountList
    int n = this->aList.size();
    for (int i = 0; i < n; ++i)
        if (this->aList[i].isThisUser(username))
        {
            aList.erase(aList.begin() + i);
            break;
        }

    // Remove Person in Library
    n = this->lPeople.size();
    for (int i = 0; i < n; i++)
        if (lPeople[i].isThisPerson(username))
        {
            lPeople.erase(lPeople.begin() + i);
            break;
        }

    return true;
}

bool Librarian::addBook(Book book)
{
    // Same idea with searchISBN
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

bool Librarian::removeBook(ull isbn)
{
    int pos = findBookPos(isbn);
    if (pos == -1)
        return false;

    // Dang lam ...

    return true;
}

bool Librarian::modifyBook(std::vector<std::string> tokens)
{
    ull _isbn = std::stoull(tokens[0]);
    int pos = Utility::searchByISBN(*this, _isbn);

    if (pos == -1 || tokens.size() != 5)
        return false;

    int i = 0;
    this->lBooks[pos].changeInfo(_isbn, tokens[++i], tokens[++i], tokens[++i], tokens[++i]);

    return true;
}

std::string Librarian::lookUpMemberByName(std::string _name)
{
}

std::string Librarian::lookUpMemberByIDCard(std::string _id)
{
}

std::string Librarian::lookUpBorrowCard(ull _id)
{
    int pos = this->getBCIndexToRemove(_id);
    return this->lBCards[pos].getInfo();
}

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
            // Thêm hàm lấy person info
            res.push_back(this->lBCards[i].toString());
        }
    }

    return res;
}

std::vector<std::string> getMemberByGender(bool gender);

std::string Librarian::createBorrowCard(ull _isbn)
{
    int pos = Utility::searchByISBN(*this, _isbn);
    std::string barCode = this->lBooks[pos].checkOut();
    if (pos != 1 && barCode != "")
    {
        // Chua trung khop du lieu, doi string thanh ull
        // BorrowCard bc(this->lBCards.size(), this->aCurUser.getID(), _isbn, barCode);
        // this->lBCards.push_back(bc);
        // return bc.toString();
    }
    return "";
}

ReturnStatus Librarian::removeBorrowCard(ull _bcID)
{
    int pos = this->getBCIndexToRemove(_bcID);
    int dateDis = 0;
    if (pos != -1)
    {
        dateDis = this->lBCards[pos].getDateDis();
        this->lBCards.erase(this->lBCards.begin() + pos);
    }

    if (dateDis == 0)
        return OnTime;

    if (dateDis < 0)
        return Late;

    if (dateDis > 0)
        return Early;
}
