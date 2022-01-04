#include "Utility.h"
// Constructor and Destructor

// Operator Overloading

// Member function
int Utility::searchByISBN(Library lib, ull _isbn)
{
    int _size = lib.lBooks.size();
    if (_isbn < lib.lBooks[0].getID() || _isbn > lib.lBooks[_size - 1].getID())
        return -1;
    int l = 0, r = _size - 1;
    while (l < r)
    {
        int pos = l + double((r - l) / double(lib.lBooks[r].getID() - lib.lBooks[l].getID())) * (_isbn - lib.lBooks[l].getID());
        if (_isbn == lib.lBooks[pos].getID())
            return pos;
        else if (_isbn < lib.lBooks[pos].getID())
            r = pos - 1;
        else
            l = pos + 1;
    }
    if (l == r && lib.lBooks[l].getID() == _isbn)
        return l;
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

std::vector<std::string> Utility::displayBooks(Library lib)
{
    std::vector<std::string> res;
    int n = lib.lBooks.size();
    for (int i = 0; i < n; ++i)
        res.push_back(lib.lBooks[i].toString());
    return res;
}

int Utility::getBooksQuantity(Library lib)
{
    int n = lib.lBooks.size();
    int total = n;
    for (int i = 0; i < n; ++i)
        total += lib.lBooks[i].getCopiesQuantity() - 1;
    return total;
}

bool Utility::enterLogin(User us, AccountList& accList)
{
    // Step1: Check User + Password (using vector<User> of AccountList)
    // Step2: If available --> Change aCurUser of AccountList
    // Step3: Done

    int l = 0, r = accList.aList.size()-1, pos;
    while (l <=r )
    {
        pos = l + (r-l)/2;
        int cmp = us.user.compare(accList.aList[pos].user);
        // True if us and aList[pos] have the same username
        if (cmp == 0)
        {
            // Check password
            if (us.pass == accList.aList[pos].pass)
            {
                accList.changeCurUser(us);
                accList.loadCurUserInfo();
                return true;
            }
            // if password is wrong --> Login false
            return false;
        }

        // username of us > username of aList[pos]
        if (cmp > 0)
            l = pos +1;
        else
            r = pos - 1;
    }

    // if can not find out username in list
    return false;
}

bool Utility::enterRegister(Library& lib, AccountList& accList, Account acc)
{
    // Library lib -> Check lPeople
    // AccountList accList -> Check aList

    // Check username
    int l = 0, r = accList.aList.size()-1, pos, temp = -1;
    while (l <= r )
    {
        pos = l + (r-l)/2;
        int cmp = acc.getUserName().compare(accList.aList[pos].user);
        // True if acc and aList[pos] have the same username
        if (cmp == 0)
        {
            temp = pos;
            break;
        }

        // username of acc > username of aList[pos]
        if (cmp > 0)
            l = pos +1;
        else
            r = pos - 1;
    }
    
    // can not register with this username
    if (temp != -1)
        return false;

    // Register
    lib.lPeople.push_back(acc.getInfo());
    User newUser(acc.getUserName(), acc.getPassword(), acc.getID(), acc.getStatus());
    accList.aList.insert(accList.aList.begin()+r+1, newUser);
    return true;
}