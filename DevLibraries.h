#pragma once
#include <regex>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define BOOKS "Books.csv"
#define PEOPLE "People.csv"
#define BORROWCARDS "BorrowCards.csv"
#define STOPWORDS "stopwords.txt"

typedef unsigned long long int ull;

class Tokenizer
{
public:
    static std::vector<std::string> Parse(std::string line, std::string seperator)
    {
        std::vector<std::string> tokens;

        int startPos = 0;
        std::size_t foundPos = line.find(seperator, startPos);

        while (foundPos != std::string::npos)
        {
            int count = foundPos - startPos;
            std::string token = line.substr(startPos, count);
            tokens.push_back(token);

            startPos = foundPos + seperator.length();

            foundPos = line.find(seperator, startPos);
        }

        int count = line.length() - startPos;
        std::string token = line.substr(startPos, count);
        tokens.push_back(token);

        return tokens;
    }
};

class Data
{
public:
    static std::vector<std::string> dStopwords;

public:
    static std::vector<std::string> removeStopWord(std::vector<std::string> _stopword, std::string _line)
    {
        std::vector<std::string> result;

        std::for_each(_line.begin(), _line.end(), [](char &c)
                      { c = ::tolower(c); });

        std::vector<std::string> tokens = Tokenizer::Parse(_line, " ");
        int i = 0, n = tokens.size();
        while (i < n)
        {
            bool equal = false;
            int left = 0, right = _stopword.size() - 1;
            do
            {
                int mid = left + (right - left) / 2;
                if (tokens[i].compare(_stopword[mid]) < 0)
                    right = mid - 1;
                else if (tokens[i].compare(_stopword[mid]) > 0)
                    left = mid + 1;
                else
                {
                    equal = true;
                    break;
                }
            } while (left < right);

            if (!equal)
                result.push_back(tokens[i]);

            ++i;
        }
        return result;
    }

    static std::vector<std::string> loadStopwords()
    {
        std::vector<std::string> result;
        std::ifstream fi(STOPWORDS);
        if (fi.is_open())
        {
            std::string sw;
            while (!fi.eof())
            {
                fi >> sw;
                result.push_back(sw);
            }
            fi.close();
        }
        return result;
    }
};