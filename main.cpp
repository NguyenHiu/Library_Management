#include "Librarian.h"
#include "DevLibraries.h"
#include "Utility.h"

std::vector<std::string> Data::dStopwords = Data::loadStopwords();

int main()
{ /*
     Librarian lib;
     lib.loadBorrowCards();

     std::cout << lib.lBCards[0].toString() << std::endl;
     std::cout << lib.lBCards[1].getReturnDate().toString() << std::endl;
     std::cout << lib.lBCards[0].getDateDis() << std::endl;
     std::cout << lib.lBCards[1].getDateDis() << std::endl;


     lib.loadBooks();
     lib.loadUsers();
     lib.loadPeople();

     std::string info = "Nguyen Trong Hieu,nguyenhieu82132@gmail,0707620014,301797241,Long An,1,08/10/2002,";
     Person newPerson(Tokenizer::Parse(info,","));
     Account newAcc(1,"Nguyen Trong Hieu", "123",newPerson);

     bool Register = Utility::enterRegister(lib,lib,newAcc);
     if (!Register)
         std::cout << "Error...\n";

     lib.saveUsers();
     lib.savePeople();
     lib.saveBooks();
  */
    // std::string line = "1061834158,Sleeping Beauty,Phillip Margolin,HarperCollinsPublishers LTD,13/10/2009,546777,306939,";
    // Book b(Tokenizer::Parse(line,","));
    // std::cout << "Default: " << line << "\nParse  : " << b.toString() << "\n";
}