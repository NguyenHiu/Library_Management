CC = g++

all: main.o
	$(CC) main.o -o main

Book.o: Book.h Book.cpp DevLibraries.h
	$(CC) -g -c Book.cpp

BookCopies.o: BookCopies.h BookCopies.cpp DevLibraries.h
	$(CC) -g -c BookCopies.cpp

BorrowCard.o: Date.h BorrowCard.h BorrowCard.cpp DevLibraries.h
	$(CC) -g -c BorrowCard.cpp

Library.o: Library.h Library.cpp DevLibraries.h
	$(CC) -g -c Library.cpp

Date.o: Date.h Date.cpp DevLibraries.h
	$(CC) -g -c Date.cpp

main.o: Date.h Book.h BookCopies.h DevLibraries.h Library.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm -f *.o
	rm main