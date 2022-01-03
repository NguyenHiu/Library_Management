CC = g++

OBJECTS = main.o Book.o BookCopies.o BorrowCard.o Utility.o Library.o Date.o AccountList.o Account.o Person.o Librarian.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

Book.o: Book.h Book.cpp DevLibraries.h
	$(CC) -g -c Book.cpp

BookCopies.o: BookCopies.h BookCopies.cpp DevLibraries.h
	$(CC) -g -c BookCopies.cpp

BorrowCard.o: Date.h BorrowCard.h BorrowCard.cpp DevLibraries.h
	$(CC) -g -c BorrowCard.cpp

Utility.o: AccountList.h Library.h Utility.h Utility.cpp DevLibraries.h
	$(CC) -g -c Utility.cpp

Library.o: Library.h Library.cpp DevLibraries.h
	$(CC) -g -c Library.cpp

Date.o: Date.h Date.cpp DevLibraries.h
	$(CC) -g -c Date.cpp

Account.o: Account.cpp Account.h Person.h
	$(CC) -g -c Account.cpp
	
AccountList.o: AccountList.h AccountList.cpp Account.h
	$(CC) -g -c AccountList.cpp

Person.o: Person.h Person.cpp Date.h
	$(CC) -g -c Person.cpp

Librarian.o: Librarian.h Librarian.cpp DevLibraries.h Date.h Library.h Account.h AccountList.h Utility.h
	$(CC) -g -c Librarian.cpp

	
main.o: Librarian.h main.cpp DevLibraries.h
	$(CC) -g -c main.cpp

clean:
	rm -f *.o
	rm main