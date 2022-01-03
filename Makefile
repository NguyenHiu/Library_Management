CC = g++

# all: main.o
# 	$(CC) main.o -o main

# Book.o: Book.h Book.cpp DevLibraries.h
# 	$(CC) -g -c Book.cpp

# BookCopies.o: BookCopies.h BookCopies.cpp DevLibraries.h
# 	$(CC) -g -c BookCopies.cpp

# BorrowCard.o: Date.h BorrowCard.h BorrowCard.cpp DevLibraries.h
# 	$(CC) -g -c BorrowCard.cpp

# Utility.o: AccountList.h Library.h Utility.h Utility.cpp
# 	$(CC) -g -c Utility.cpp

# Library.o: Library.h Library.cpp DevLibraries.h
# 	$(CC) -g -c Library.cpp

# Date.o: Date.h Date.cpp DevLibraries.h
# 	$(CC) -g -c Date.cpp

# main.o: Date.h Book.h BookCopies.h DevLibraries.h Library.h main.cpp
# 	$(CC) -g -c main.cpp

OBEJCTS = main.o Account.o AccountList.o Date.o Person.o
CFLAGS = -g

all: $(OBEJCTS)
	$(CC) $(OBEJCTS) -o main

Account.o: Account.cpp Account.h Person.h
	$(CC) $(CFLAGS) -c Account.cpp
	
AccountList.o: AccountList.h AccountList.cpp Account.h
	$(CC) $(CFLAGS) -c AccountList.cpp

Date.o: Date.h Date.cpp DevLibraries.h
	$(CC) $(CFLAGS) -c Date.cpp
	
Person.o: Person.h Person.cpp Date.h
	$(CC) $(CFLAGS) -c Person.cpp
	
main.o: AccountList.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o
	rm main