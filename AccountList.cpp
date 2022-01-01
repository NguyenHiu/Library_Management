#include "AccountList.h"

AccountList::AccountList() {}

// 
bool AccountList::loadUsers()
{
    std::string fileName = "User.csv";

    std::ifstream f;
    f.open(fileName);
    if (f.is_open() == false)
        return false;

    std::string us, pw, id;
    while (getline(f, us))
    {
        // neu chua lay duoc password ma da het file thi file sai
        if (f.eof()) {
            f.close();
            aList.clear();
            return false;
        }
        f >> pw >> id; 
        aList.push_back(User(us, pw, id));

        us = ""; pw = ""; id = "";
    }

    f.close();
    return true;
}

// Lấy thông tin của Person ứng với username từ tệp Person.csv cho vào aCurUser
bool AccountList::loadCurUserInfo()
{
    std::string fileName = "Person.csv";
    
    std::ifstream f;
    f.open(fileName);
    if (f.is_open() == false)
        return false;

    std::string ans = aCurUser.getUserName();
    Person temp;
    while (f >> temp)
    {
        if (!temp.isThisPerson(ans))
            continue;

        aCurUser.setInfo(temp);
        break;
    }

    f.close();
    return true;
}

bool AccountList::saveUsers()
{
    std::string fileName = "User.csv";

    std::ofstream f;
    f.open(fileName);

    for (int i = 0; i < aList.size()-1; i++)
    {
        f << aList[i].user << "\n" 
          << aList[i].pass << "\n"
          << aList[i].ID   << "\n";
    }

    // Tach ra de dam bao khong co dong trang o cuoi file.
    f << aList[aList.size()-1].user << "\n"
      << aList[aList.size()-1].pass << "\n"
      << aList[aList.size()-1].ID;

    f.close();
    return true;
}

// Gửi person trở về file 
bool AccountList::saveCurUserInfo()
{
    std::string fileName = "Person.csv";

    std::ifstream fi;
    fi.open(fileName);

    std::string us = aCurUser.getUserName();
    std::vector<Person> pList;
    Person temp;
    int tempPos = 0, pos = -1;
    bool found = false;
    // Kiểm tra xem Person có nằm trong file chưa,
    // Nếu có thì lấy vị trí Person ra để ghi đè
    while (fi >> temp)
    {

        if (temp.isThisPerson(us))
        {
            found = true;
            pos = tempPos;
        }

        tempPos = fi.tellg();

        if (found)
            pList.push_back(temp);
    }
    fi.close();

    // Nếu person chưa nằm trong file thì ghi vào cuối file
    if (pos == -1)
    {
        std::ofstream fo;
        fo.open(fileName, std::ios::ate);
        fo << temp;
        fo.close();
        return true;
    }

    // Nếu đã nằm trong file thì seek đến vị trí đó,
    // Ghi đè và sau đó ghi các Person còn lại ở sau (đã lưu trong pList)
    std::fstream fo(fileName, std::ios::in | std::ios::out | std::ios::app);
    fo.seekg(pos, fo.beg);
    fo << aCurUser.getInfo();
    for (auto i : pList)
        fo << i;

    fo.close();
    return true;
}
