#include "AccountList.h"

AccountList::AccountList() {}

bool AccountList::loadUsers()
{
    std::string fileName = "User.csv";

    ifstream f;
    f.open(fileName);
    if (f.is_open() == false)
        return false;

    std::string us, pw;
    while (f >> us)
    {
        // neu chua lay duoc password ma da het file thi file sai
        if (f.eof()) {
            f.close();
            aList.clear();
            return false;
        }
        f >> pw;
        aList.push_back(User(us, pw));

        us = ""; pw = "";
    }

    f.close();
    return true;
}

bool AccountList::loadCurUserInfo()
{
    // hình như hàm thiếu username nhỉ
    // hay hàm này nhận username + password từ UI hả ._.
}

bool AccountList::saveUsers()
{
    std::string fileName = "User.csv";

    ofstream f;
    f.open(fileName);

    for (int i = 0; i < aList.size()-1; i++)
    {
        f << aList[i].user << "\n" 
          << aList[i].pass << "\n";
    }

    // Tach ra de dam bao khong co dong trang o cuoi file.
    f << aList[aList.size()-1].user << "\n"
      << aList[aList.size()-1].pass;

    f.close();
    return true;
}

bool AccountList::saveCurUserInfo()
{
    // Hàm này chắc đợi xem hàm loadCurUserInfo thế nào đã
}