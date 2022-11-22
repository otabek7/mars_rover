// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using std::ostream;

class MyString
{
private:
    char *string;
    size_t stringCap;
    size_t stringSize;
    // private data vars
public:
    MyString(); // default
    MyString(const MyString &str);
    MyString &operator=(const MyString &str); // MyString () copy assignment operator
    MyString(const char *str);
    ~MyString(); // Destructor
    // Rule of 3 implemented

    size_t sizeOf(const char *secondStr); // MyString () getsTheSize
    size_t capacity() const noexcept;     // MyString () checksCapacity
    size_t size() const noexcept;         // MyString () checksSize
    size_t length() const noexcept;       // MyString () checksLength
    size_t find(const MyString &str, size_t pos = 0) const noexcept;

    char *crtStr();
    const char *data() const noexcept;
    const char &front() const;        // MyString () char at front
    const char &at(size_t pos) const; // MyString () char at

    bool empty() const noexcept; // MyString () isEmpty bool
    void clear() noexcept;       // MyString () isClear void
    void resize(size_t n);       // MyString () resizes
    friend MyString operator+(const MyString &s1, const MyString &s2);

    friend ostream &operator<<(ostream &os, const MyString &str);            // MyString () <<
    friend int operator==(const MyString &string1, const MyString &string2); // MyString()  ==

    MyString &operator+=(const MyString &str); // MyString () +=
};
#endif