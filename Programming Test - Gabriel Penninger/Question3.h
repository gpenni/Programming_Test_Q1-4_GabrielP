#ifndef QUESTION3_H
#define QUESTION3_H

#include <iostream>
#include <cstring>  // For strcpy, strlen, strcmp

class slow_string {
private:
    char* data;  // Raw character array

public:
    // Constructors & Destructor
    slow_string();
    slow_string(const char* str);
    slow_string(const slow_string& other);  // Copy constructor
    slow_string(slow_string&& other) noexcept;  // Move constructor
    ~slow_string();

    // Assignment Operators
    slow_string& operator=(const slow_string& other);  // Copy assignment
    slow_string& operator=(slow_string&& other) noexcept;  // Move assignment

    // Member Functions
    size_t length() const;
    const char* c_str() const;

    // Operators
    slow_string operator+(const slow_string& other) const;
    bool operator==(const slow_string& other) const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& os, const slow_string& str);
    friend std::istream& operator>>(std::istream& is, slow_string& str);
};

#endif 