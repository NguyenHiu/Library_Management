#pragma once
#include "DevLibraries.h"
#include "BookCopies.h"

class Book
{
public:
	friend class Utility;
	friend class Library;

private:
	ull bISBN;
	std::string bTitle, bAuthor, bPublisher;
	std::vector<BookCopies> bCopies;
	// Sort ISBN increasing
	// ISBN: 978/979 - Country/Language - Publisher - ID Book - Test number

public:
	Book(std::vector<std::string> bTokens);
	/* {
		int i = 0, n = bTokens.size();
		bISBN = stoull(bTokens[i++]);
		// Check ISBN
		bTitle = bTokens[i++];
		bAuthor = bTokens[i++];
		bPublisher = bTokens[i++];
		while (i < n)
		{
			std::string barCode = bTokens[i++];
			Date *pubDate = Date::Parse(bTokens[i++]);
			if (pubDate)
			{
				BookCopies copies(barCode, *pubDate);
				bCopies.push_back(copies);
			}
		}
	} */

public:
	bool operator==(const Book &other) const;
	/* {
		return (bISBN == other.bISBN);
	} */

public:
	friend std::ostream &operator<<(std::ostream &os, const Book &b);
	/* {
		os << "ISBN: " << b.bISBN << std::endl
		   << "Name: " << b.bTitle << std::endl
		   << "Author: " << b.bAuthor << std::endl
		   << "Publisher: " << b.bPublisher;
		return os;
	} */
};