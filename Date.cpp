#include "Date.h"

// Constructor and Destructor
Date::Date()
{
    time_t rawTime = time(nullptr);
    tm *timeInfo = localtime(&rawTime);
    this->dDay = timeInfo->tm_mday;
    this->dMon = timeInfo->tm_mon + 1;
    this->dYear = timeInfo->tm_year + 1900;
}

Date::Date(const int &date, const int &mon, const int &year)
{
    this->dDay = date;
    this->dMon = mon;
    this->dYear = year;
}

Date::Date(const Date &other)
{
    this->dDay = other.dDay;
    this->dMon = other.dMon;
    this->dYear = other.dYear;
}

// Operator overloading
Date Date::operator+(const int &num)
{
    Date temp(*this);
    temp.dDay += num;
    while (temp.dDay > temp.maxDay())
    {
        temp.dDay -= temp.maxDay();
        temp.toNextMonth();
    }
    return temp;
}

// Member function
void Date::toNextMonth()
{
    if (this->dMon == 12)
    {
        this->dMon = 1;
        this->dYear++;
    }
    else
        this->dMon++;
}

int Date::maxDay()
{
    if (this->dMon != 2 || Date::IsLeapYear(this->dYear) == false)
        return DAY_A_MONTH[this->dMon - 1];
    else
        return SpecialFeb;
}

void Date::print()
{
    cout << this->dDay << "/" << this->dMon << "/" << this->dYear << endl;
}

Date *Date::Parse(std::string line)
{
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
}

bool Date::IsLeapYear(int _year)
{
    return (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0));
}

bool Date::IsValidDate(int _date, int _mon, int _year)
{
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
}
