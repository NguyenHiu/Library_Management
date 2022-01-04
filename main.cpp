#include "Librarian.h"
#include "DevLibraries.h"
#include "Utility.h"
#include <stdio.h>

std::vector<std::string> Data::dStopwords = Data::loadStopwords();

int main()
{ 
    Librarian lib;
    lib.loadBooks();
    lib.loadUsers();
    lib.loadPeople();

    while (1)
    {
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Logout\n";
        std::cout << "4. Exit\n";
        int choose; std::cin >> choose;
        std::cin.ignore();
        if (choose == 1)
        {
            std::cout << " *** Login:\n";
            std::vector<std::string> info(4);
            info[0] = std::to_string(lib.sizePeople());
            std::cout << " + Username: "; getline(std::cin, info[1]);
            std::cout << " + Password: "; getline(std::cin, info[2]);
            info[3] = "Active";

            int check = Utility::enterLogin(User(info), lib);
            // return -1: password incorrect
            // return  0: username incorrect
            // return  1: login successful
            if (check == -1)
                std::cout << "XXXX Sai nhap khau.\n";
            else if (check == 0)
                std::cout << "XXXX Sai Ten dang nhap.\n";
            else if (check == 1)
                std::cout << "----> Dang nhap thanh cong.\n";
            else
                lib.showCurUser();
        }
        else if (choose == 2)
        {
            std::cout << " *** Register (Mat khau, phai co it nhat: 6 chu, 1 chu hoa, 1 chu thuong va 1 so.):\n";
            // vector: Id, Username, Password, Status, Email, Phone, ID Card, Address, Gender, Day of Birth
            std::vector<std::string> info(10);
            info[0] = std::to_string(lib.sizePeople());
            std::cout << " + Username: "; getline(std::cin, info[1]);
            std::cout << " + Password: "; getline(std::cin, info[2]);
            info[3] = "Active";
            std::cout << " + Email: "; getline(std::cin, info[4]);
            std::cout << " + Phone: "; getline(std::cin, info[5]);
            std::cout << " + ID Card: "; getline(std::cin, info[6]);
            std::cout << " + Address: "; getline(std::cin, info[7]);
            std::cout << " + Gender: "; getline(std::cin, info[8]);
            std::cout << " + Day of Birth: "; getline(std::cin, info[9]);
            
            int check = Utility::enterRegister(lib, lib, info);
            // return 0: da ton tai username
            // return 1: password chua dat yeu cau
            // return 2: username chua dat yeu cau
            // return 3: email chua dat yeu cau
            // return 4: phone chua dat yeu cau
            // return 5: iD Card chua dat yeu cau
            // return 6: address chua dat yeu cau
            // return 7: day of Birth chua dat yeu cau
            // return 8: -> valid
            if (check == 0)
                std::cout << "XXXX Ten dang nhap da ton tai.\n";
            if (check == 1)
                std::cout << "XXXX Mat khau chua dat yeu cau.\n";
            if (check == 2)
                std::cout << "XXXX Ten dang nhap chua dat yeu cau.\n";
            if (check == 3)
                std::cout << "XXXX Email chua dat yeu cau.\n";
            if (check == 4)
                std::cout << "XXXX So dien thoai chua dat yeu cau.\n";
            if (check == 5)
                std::cout << "XXXX So CMND/CCCD chua dat yeu cau.\n";
            if (check == 6)
                std::cout << "XXXX Dia chi chua dat yeu cau.\n";
            if (check == 7)
                std::cout << "XXXX Ngay sinh chua dat yeu cau.\n";
            else if (check == 8)
                std::cout << "----> Dang ky thanh cong. Dang nhap de tiep tuc\n";
        }
        else if (choose == 3)
            lib.changeCurUser(User());
        else
            break;
    }

    lib.saveUsers();
    lib.savePeople();
    lib.saveBooks();
}