#include "Question3.h"

// Default constructor
slow_string::slow_string() : data(new char[1]) {
    data[0] = '\0';
}

// Parameterized constructor 
slow_string::slow_string(const char* str) {
    data = new char[strlen(str) + 1];
    strcpy_s(data, strlen(str) + 1, str);
}

// Copy constructor (Deep Copy)
slow_string::slow_string(const slow_string& other) {
    data = new char[strlen(other.data) + 1];
    strcpy_s(data, strlen(other.data) + 1, other.data);
}

// Move constructor (Steal resources)
slow_string::slow_string(slow_string&& other) noexcept : data(other.data) {
    other.data = nullptr;
}

// Destructor
slow_string::~slow_string() {
    delete[] data;
}

// Copy assignment operator
slow_string& slow_string::operator=(const slow_string& other) {
    if (this != &other) {
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
    }
    return *this;
}

// Move assignment operator
slow_string& slow_string::operator=(slow_string&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

// Get length
size_t slow_string::length() const {
    return strlen(data);
}

// Get C-string
const char* slow_string::c_str() const {
    return data;
}

// Concatenation
slow_string slow_string::operator+(const slow_string& other) const {
    size_t newLength = strlen(data) + strlen(other.data);
    char* newData = new char[newLength + 1];

    strcpy_s(newData, newLength + 1, data);
    strcat_s(newData, newLength + 1, other.data);

    slow_string result(newData);
    delete[] newData;
    return result;
}

// Equality operator
bool slow_string::operator==(const slow_string& other) const {
    return strcmp(data, other.data) == 0;
}

// Subscript operator
char& slow_string::operator[](size_t index) {
    return data[index];
}

const char& slow_string::operator[](size_t index) const {
    return data[index];
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const slow_string& str) {
    os << str.data;
    return os;
}

// Input stream operator
std::istream& operator>>(std::istream& is, slow_string& str) {
    char buffer[256];  // Fixed buffer size to make it easier to see haha
    is.getline(buffer, 256);
    str = slow_string(buffer);  // Use assignment operator
    return is;
}