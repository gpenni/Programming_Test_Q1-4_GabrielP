#ifndef QUESTION4_H
#define QUESTION4_H

#include <iostream>
#include <cmath>

class Question4 {
private:
    float x, y, z;  // Private data members

public:
    // Constructors
    Question4();  // Default constructor (0,0,0)
    Question4(float x, float y, float z);  // Parameterized constructor
    Question4(const Question4& other);  // Copy constructor

    // Operator Overloads with some vector magic
    Question4 operator+(const Question4& other) const;
    Question4 operator-(const Question4& other) const;
    Question4 operator*(float scalar) const;
    Question4 operator/(float scalar) const;

    // Dot & Cross Product
    float dot(const Question4& other) const;
    Question4 cross(const Question4& other) const;

    // Magnitude & Normalization
    float magnitude() const;
    Question4 normalized() const;

    void print() const;

    // Getters
    float getX() const;
    float getY() const;
    float getZ() const;

    // Friend Functions for Output
    friend std::ostream& operator<<(std::ostream& os, const Question4& v);
};

#endif  