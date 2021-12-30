#include "Library.h"
#include "In.h"
#include <windows.h>

std::vector<std::string> Data::dStopwords = Data::loadStopwords();

int main()
{   
    In in;
    in.loadAccounts();

    int cnt = 0, k;
    std::string us, pw;
    Account* temp;

    while(1)
    {
        std::cout << "--> Login / Register / Exit (0/1/2): ";
        std::cin >> k;
        if (k != 0 && k != 1 && k != 2)
            continue;
        if (k == 2) return 1;
        if (k == 0)
            std::cout << "- Login:\n";
        else 
            std::cout << "- Register:\n";
        
        std::cout << "\t(+) Username: ";
        std::cin >> us;
        std::cout << "\t(+) Password: ";
        std::cin >> pw;

        if (k == 1)
        {
            bool reg = In::Register(in, us, pw);
            if (reg == false)
            {
                std::cout << "(X) Registration failed: Username already exists.\n";
            }
            else
            {
                std::cout << "(V) Registration Successful. Please Login.\n";
            }
            
            continue;
        }
        else
        {
            int check = In::Login(in, us, pw, temp);
            if (check == -1)
            {
                std::cout << "(X) Login failed: Password is incorrect.\n";
                continue;
            }
            else if (check == 0)
            {
                std::cout << "(X) Login failed: Username is incorrect.\n";
                continue;
            }
            std::cout << "(V) Login successful.\n";
            break;
            
        }

    }

    Library lib;
    lib.loadBooks();
    lib.createSearchData();

    int type = 0;
    do
    {
        std::cout << "\t.-------------------------.\n"
                  << "\t| -> 1. Search By Title   |" << std::endl
                  << "\t| -> 2. Search By ISBN    |" << std::endl
                  << "\t| -> 3. Exit              |" << std::endl
                  << "\t.-------------------------." << std::endl;
        std::cout << "--> Your choice: ";
        std::cin >> type;
        if (type == 3) 
            break;
        if (type == 1)
        {
            std::string query = "";
            std::cout << "(+) Enter your query: ";
            std::cin.ignore();
            std::getline(std::cin, query);
            std::vector<Book> res = Utility::searchByTitle(lib, query);
            if (!res.empty())
            {
                std::cout << "(V) Result:\n";
                for (int i = 0; i < 4 && i < res.size(); i++)  
                    std::cout << "-" << res[i] << "\n\n";
                std::cout << std::endl;
            }
            else
                std::cout << "(X) No results found.\n";
        }
        else if (type == 2)
        {
            ull ISBN = 0;
            std::cout << "(+) Enter your ISBN: ";
            std::cin >> ISBN;
            Book *result = Utility::searchByISBN(lib, ISBN);
            if (result)
            {   
                std::cout << "(V) Result:\n";
                std::cout << "-" << *result << "\n\n";
                delete result;
                result = nullptr;  
            } 
            else
                std::cout << "(X) No results found.\n";
            
        }
    } while (type == 1 || type == 2);
    return 0;
}