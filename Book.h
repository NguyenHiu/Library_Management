#pragma once
#include "DevLibraries.h"
#include "BookCopies.h"
#include "Date.h"

class Book
{
public:
	friend class Utility;
	friend class Library;

private:
	ull bISBN; // 10 digits ISBN
	std::string bTitle, bAuthor, bPublisher;
	Date bPubDate;
	std::vector<BookCopies> bCopies;

public:
	Book();
	Book(std::vector<std::string> bTokens);

public:
	bool operator==(const Book &other) const;

public:
	void changeInfo(ull _isbn, std::string _title, std::string _author, std::string _publisher, std::string _pubDate);
	std::string checkOut();
	std::string toString() const;

	ull getISBN();
};