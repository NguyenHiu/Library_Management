#pragma once
#include "DevLibraries.h"
using namespace std;

const int DAY_A_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int SpecialFeb = 29;

class Date
{
private:
    unsigned short dDay, dMon, dYear;

public:
    Date();
    /* {
        time_t rawTime = time(nullptr);
        tm *timeInfo = localtime(&rawTime);
        dDay = timeInfo->tm_mday;
        dMon = timeInfo->tm_mon + 1;
        dYear = timeInfo->tm_year + 1900;
    } */

    Date(const int &date, const int &mon, const int &year);
    /* {
        dDay = date;
        dMon = mon;
        dYear = year;
    } */

    Date(const Date &other);
    /* {
        dDay = other.dDay;
        dMon = other.dMon;
        dYear = other.dYear;
    } */

public:
    Date operator+(const int &num);
    /* {
        Date temp(*this);
        temp.dDay += num;
        while (temp.dDay > temp.maxDay())
        {
            temp.dDay -= temp.maxDay();
            temp.toNextMonth();
        }
        return temp;
    } */

public:
    void toNextMonth();
    /* {
        if (dMon == 12)
        {
            dMon = 1;
            dYear++;
        }
        else
            dMon++;
    } */

    int maxDay();
    /* {
        if (dMon != 2 || Date::IsLeapYear(dYear) == false)
            return DAY_A_MONTH[dMon - 1];
        else
            return SpecialFeb;
    } */

    void print();
    /* {
        cout << dDay << "/" << dMon << "/" << dYear << endl;
    } */

public:
    static Date *Parse(std::string line);
    /* {
        std::vector<std::string> tokens = Tokenizer::Parse(line, "/");
        std::vector<int> numbers;

        for (auto i = 0; i < tokens.size(); ++i)
        {
            auto num = stoi(tokens[i]);
            numbers.push_back(num);
        }

        if (Date::IsValidDate(numbers[0], numbers[1], numbers[2]))
            return new Date(numbers[0], numbers[1], numbers[2]);
        else
            return nullptr;
    } */

    static bool IsLeapYear(int _year);
    /* {
        return (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0));
    } */

    static bool IsValidDate(int _date, int _mon, int _year);
    /* {
        if (_date <= 31 && _date >= 1 && _mon >= 1 && _mon <= 12 && _year >= 0)
        {
            if ((_mon == 4 || _mon == 6 || _mon == 9 || _mon == 11) && _date <= 30)
                return true;
            if (_mon == 2)
            {
                if (Date::IsLeapYear(_year))
                    return (_date <= 29);
                return (_date <= 28);
            }
            return true;
        }
        return false;
    } */
};