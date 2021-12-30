#pragma once
#include "DevLibraries.h"
#include "BookCopies.h"

class Book
{
public:
	friend class Utility;
	friend class Library;

private:
	ull bISBN; // 10 digits ISBN
	std::string bTitle, bAuthor, bPublisher;
	Date pubDate;
	std::vector<BookCopies> bCopies;

public:
	Book(std::vector<std::string> bTokens);

public:
	void changeInfo(ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _pubDate);
	std::string toString() const;

public:
	bool operator==(const Book &other) const;

public:
	//friend std::ostream &operator<<(std::ostream &os, const Book &b);
};