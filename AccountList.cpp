#include "AccountList.h"

AccountList::AccountList() {}

// Checked!
bool AccountList::loadUsers()
{
    std::string fileName = "Users.csv";

    std::ifstream f;
    f.open(fileName);
    if (f.is_open() == false)
        return false;

    std::string line;
    while (!f.eof())
    {
        getline(f, line);
        std::vector<std::string> info = Tokenizer::Parse(line, ",");
        std::cout << "\n";
        aList.push_back(User(info));
        line = "";
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

    std::string ans = aCurUser.getUserName(), line;
    while (!f.eof())
    {
        getline(f, line);
        Person temp(Tokenizer::Parse(line, ","));
        if (temp.isThisPerson(ans))
        {
            aCurUser.updateInfo(temp);
            break;
        }
    }

    f.close();
    return true;
}

bool AccountList::changeCurUser(std::string us)
{
    int l = 0, r = aList.size()-1, pos;
    while (l <= r)
    {
        pos = l + (r-l)/2;
        if (aList[pos].isThisUser(us))
        {
            aCurUser.updateUser(aList[pos].user,aList[pos].pass,aList[pos].ID,aList[pos].status);
            return true;
        }
        if (us.compare(aList[pos].user) > 0) // us > user
            l = pos + 1;
        else
            r = pos - 1;       
    }
    return false;
}

bool AccountList::saveUsers()
{
    std::string fileName = "Users.csv";

    std::ofstream f;
    f.open(fileName, std::ios::out);

    for (int i = 0; i < aList.size(); i++)
    {
        if (i != 0) f << "\n";
        f << aList[i].ID << "," 
          << aList[i].user << ","
          << aList[i].pass << ","
          << (aList[i].status == Active ? "Active" : "Canceled") << ",";
    }

    f.close();
    return true;
}

// Gửi person trở về file 
bool AccountList::saveCurUserInfo()
{
    std::string fileName = "Person.csv";

    std::ifstream fi;
    fi.open(fileName);

    std::string us = aCurUser.getUserName(), temp;
    std::vector<Person> pList;
    Person ptemp;
    int tempPos = 0, pos = -1;
    bool found = false;
    // Kiểm tra xem Person có nằm trong file chưa,
    // Nếu có thì lấy vị trí Person ra để ghi đè
    while (!fi.eof())
    {
        getline(fi, temp);
        ptemp.changeProfile(Tokenizer::Parse(temp, ","));

        if (found)
            pList.push_back(ptemp);

        if (ptemp.isThisPerson(us))
        {
            found = true;
            pos = tempPos;
        }

        tempPos = fi.tellg();

    }
    fi.close();

    std::cout << " ** Pos: " << pos << "\n";

    // Nếu person chưa nằm trong file thì ghi vào cuối file
    if (pos == -1)
    {
        std::fstream fo;
        fo.open(fileName, std::ios::out | std::ios::app);
        if (fo.tellp() != 0)
            fo << "\n";
        aCurUser.getInfo().writeOnFile(fo);
        fo.close();
        return true;
    }

    // Nếu đã nằm trong file thì seek đến vị trí đó,
    // Ghi đè và sau đó ghi các Person còn lại ở sau (đã lưu trong pList)
    std::fstream fo(fileName, std::ios::in | std::ios::out | std::ios::ate);
    fo.seekp(pos, fo.beg);
    aCurUser.getInfo().writeOnFile(fo);
    for (auto i : pList)
    {
        fo << "\n";
        i.writeOnFile(fo);
    }

    fo.close();
    return true;
}