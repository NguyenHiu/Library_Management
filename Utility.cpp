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


// return -1: password incorrect
// return  0: username incorrect
// return  1: login successful
int Utility::enterLogin(User us, AccountList& accList)
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
            return -1;
        }

        // username of us > username of aList[pos]
        if (cmp > 0)
            l = pos +1;
        else
            r = pos - 1;
    }

    // if can not find out username in list
    return 0;
}

// return 0: da ton tai username
// return 1: password chua dat yeu cau
// return 2: username chua dat yeu cau
// return 3: email chua dat yeu cau
// return 4: phone chua dat yeu cau
// return 5: iD Card chua dat yeu cau
// return 6: address chua dat yeu cau
// return 7: day of Birth chua dat yeu cau
// return 8: -> valid

// AccInfo: Id, Username, Password, Status, Email, Phone, ID Card, Address, Gender, Day of Birth
int Utility::enterRegister(Library& lib, AccountList& accList, std::vector<std::string> AccInfo)
{
    // Library lib -> Check lPeople
    // AccountList accList -> Check aList

    std::regex PASSWORD("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{6,}$");
    
    // Check username
    int l = 0, r = accList.aList.size()-1, pos, temp = -1;
    while (l <= r )
    {
        pos = l + (r-l)/2;
        int cmp = AccInfo[1].compare(accList.aList[pos].user);
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
        return 0;
    
    // check password
    if (!std::regex_match(AccInfo[2], PASSWORD))
        return 1;

    // check information 
    int check = Person::checkInfo(AccInfo);
    if (check != 6)
        return check+2;

    std::vector<std::string> newUser = {AccInfo[0],AccInfo[1],AccInfo[2],AccInfo[3]},
                             newPerson = {AccInfo[1],AccInfo[4],AccInfo[5],AccInfo[6],AccInfo[7],AccInfo[8],AccInfo[9]};
    // Register
    lib.lPeople.push_back(Person(newPerson));
    accList.aList.insert(accList.aList.begin()+r+1, newUser);
    return 8;
}


bool Utility::enterLogOut() 
{
    // Thoat ra giao dien chinh
    return true;
}