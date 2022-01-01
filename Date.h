#pragma once
#include "DevLibraries.h"
#include <sstream>
#include <iostream>

const int DAY_A_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int SpecialFeb = 29;

class Date
{
private:
    unsigned short dDay, dMon, dYear;

public:
    Date();
    Date(const int &date, const int &mon, const int &year);
    Date(const Date &other);

public:
    Date operator+(const int &num);
    int operator-(const Date &other);
    Date &operator=(const Date &other);
    bool operator==(const Date &other);
    bool operator>(const Date &other);
    friend std::istream& operator>>(std::ifstream& in, Date&);

public:
    void toNextMonth();
    int maxDay();
    std::string toString() const;

public:
    static Date Parse(std::string line);
    static bool IsLeapYear(int _year);
    static bool IsValidDate(int _date, int _mon, int _year);
};