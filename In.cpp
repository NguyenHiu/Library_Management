/* #include "In.h"

bool In::loadAccounts()
{
    std::ifstream fi; fi.open("Account.csv");
    if (fi.is_open())
    {
        std::string line = "";
        while (!fi.eof())
        {
            std::getline(fi, line);
            std::vector<std::string> tokens = Tokenizer::Parse(line, ",");
            list.push_back(tokens[0]);
            list.push_back(tokens[1]);
            list.push_back(tokens[2]);
        }
        fi.close();
        return true;
    }
    return false;
}

int In::Login(In in, std::string us, std::string pw, Account* temp)
{
    for (int i = 1; i < in.list.size(); i+=3)
        if (us == in.list[i])
        {
            if (us == LibrarianN && pw == in.list[i+1])
                temp = new Librarian();
            else if(pw == in.list[i+1])
                temp = new Member();
            else
                return -1; // Sai mat khau
            return 1; //Dang nhap thanh cong
        }

    return 0; // Tai khoan khong ton tai
}

bool In::Register(In &in, std::string us, std::string pw)
{
    for (int i = 1; i < in.list.size(); i+=3)
        if (us == in.list[i])
            return 0; // Da ton tai 

    in.list.push_back(std::to_string(stoi(in.list[in.list.size()-3])+1));
    in.list.push_back(us); 
    in.list.push_back(pw);
    return 1; // Tao thanh cong
} */