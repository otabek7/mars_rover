// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
using std::cout, std::endl, std::ostream;
MyString operator+(const MyString &s1, const MyString &s2)
{
    char *p = new char[s1.length() + s2.length() + 1];
    int len = s1.length() + s2.length();
    int i = 0, j = 0;
    for (; i < s1.length(); i++)
        p[i] = s1.string[i];
    for (; i < len; i++, j++)
        p[i] = s2.string[j];
    p[i] = '\0';

    MyString sAdd(p);
    return sAdd;
}
MyString::MyString()
{
    stringSize = (0);

    stringCap = (1);
    string = (new char[stringCap]);

    string[0] = '\0';
}

MyString::MyString(const MyString &str)
{
    stringCap = (str.stringCap);
    string = (new char[str.stringCap]);
    stringSize = (str.stringSize);

    size_t i = 0;

    while (i < this->stringCap)
    {
        string[i] = str.string[i];
        i++;
    }
}

MyString &MyString::operator=(const MyString &str)
{
    if (this != &str)
    {
        clear();
        delete[] string;

        string = nullptr;
        this->stringCap = str.stringCap;
        this->stringSize = str.stringSize;

        string = new char[str.stringCap];
        size_t i = 0;
        while (i < this->stringCap)
        {
            string[i] = str.string[i];
            i++;
        }
    }
    return *this;
}

MyString &MyString::operator+=(const MyString &str)
{
    size_t oldSize = stringSize;
    resize(stringSize + str.stringSize);
    size_t i = oldSize;
    while (i < stringSize)
    {
        string[i] = str.at(i - oldSize);
        i++;
    }
    return *this;
}

MyString::MyString(const char *str)
{
    stringCap = (sizeOf(str) + 1);
    string = (crtStr());
    stringSize = (sizeOf(str));
    size_t i = 0;

    while (i < stringCap)
    {
        string[i] = str[i];
        i++;
    }
}

MyString::~MyString()
{
    if (string != nullptr)
        delete[] string;

    stringSize = 0;
    string = nullptr;
    stringCap = 1;
}

size_t MyString::sizeOf(const char *secondStr)
{
    size_t stringySize = 0;
    while (secondStr[stringySize] != '\0')
    {
        stringySize++;
    }
    return stringySize;
}

size_t MyString::capacity() const noexcept
{
    return stringCap;
}

size_t MyString::size() const noexcept
{
    return stringSize;
}

size_t MyString::length() const noexcept
{
    return stringSize;
}

size_t MyString::find(const MyString &str, size_t pos) const noexcept
{
    size_t i = pos;
    bool trigger;
    while (i < stringSize)
    {
        trigger = true;
        if (string[i] == str.at(0))
        {
            if (i <= (stringSize - str.stringSize))
            {
                for (size_t j = 0; j < str.size(); j++)
                {
                    if (str.at(j) != string[i + j])
                    {
                        trigger = false;
                        break;
                    }
                }
                if (trigger)
                    return i;
            }
        }
        i++;
    }
    return -1;
}

const char *MyString::data() const noexcept
{
    return string;
}

char *MyString::crtStr()
{
    this->string = new char[this->stringCap];
    return this->string;
}

const char &MyString::front() const
{
    return string[0];
}

const char &MyString::at(size_t pos) const
{
    if (pos < stringSize)
        return string[pos];

    throw std::out_of_range("MyString at: out of bounds");
}

bool MyString::empty() const noexcept
{

    if (stringSize <= 0)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &os, const MyString &str)
{
    os.clear();
    unsigned int i = 0;
    while (i < str.size())
    {
        os << str.string[i];
        i++;
    }
    return os;
}

void MyString::clear() noexcept
{
    delete[] string;
    stringSize = 0;
    stringCap = 1;
    string = new char[stringCap];
    string[0] = '\0';
}

void MyString::resize(size_t n)
{
    char *secondStr = new char[n + 1];
    if (n > this->stringSize)
    {
        size_t i = 0;
        while (i < n + 1)
        {
            if (i >= stringSize)
                secondStr[i] = '\0';

            else
                secondStr[i] = this->string[i];
            i++;
        }
    }
    else
    {
        size_t k = 0;
        while (k < n)
        {
            secondStr[k] = string[k];
            k++;
        }
    }
    secondStr[n] = '\0';
    delete[] string;
    string = secondStr;
    stringCap = n + 1;
    stringSize = n;
}
