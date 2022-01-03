#include "Librarian.h"
#include "DevLibraries.h"

std::vector<std::string> Data::dStopwords = Data::loadStopwords();

int main()
{
    Librarian lib;
    lib.loadBooks();
    lib.loadUsers();
    lib.loadPeople();

    lib.saveUsers();
    lib.savePeople();
    lib.saveBooks();

    // std::string line = "1061834158,Sleeping Beauty,Phillip Margolin,HarperCollinsPublishers LTD,13/10/2009,546777,306939,";
    // Book b(Tokenizer::Parse(line,","));
    // std::cout << "Default: " << line << "\nParse  : " << b.toString() << "\n";
}