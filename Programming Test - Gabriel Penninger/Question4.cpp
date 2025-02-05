#include "Question4.h"

// Default constructor initializes at 0 vector
Question4::Question4() : x(0.0f), y(0.0f), z(0.0f) {}

// Parameterized constructor
Question4::Question4(float x, float y, float z) : x(x), y(y), z(z) {}

// Copy constructor
Question4::Question4(const Question4& other) : x(other.x), y(other.y), z(other.z) {}

// Addition
Question4 Question4::operator+(const Question4& other) const {
    return Question4(x + other.x, y + other.y, z + other.z);
}

// Subtraction
Question4 Question4::operator-(const Question4& other) const {
    return Question4(x - other.x, y - other.y, z - other.z);
}

// Scalar multiplication
Question4 Question4::operator*(float scalar) const {
    return Question4(x * scalar, y * scalar, z * scalar);
}

// Scalar division
Question4 Question4::operator/(float scalar) const {
    if (scalar == 0.0f) throw std::runtime_error("Division by zero!");
    return Question4(x / scalar, y / scalar, z / scalar);
}

// Dot product
float Question4::dot(const Question4& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Cross product
Question4 Question4::cross(const Question4& other) const {
    return Question4(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Magnitude of vector
float Question4::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalized vector
Question4 Question4::normalized() const {
    float mag = magnitude();
    if (mag == 0.0f) throw std::runtime_error("Cannot normalize a zero vector!");
    return *this / mag;
}

// Print vector (for debug haha)
void Question4::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}

// Getters
float Question4::getX() const { return x; }
float Question4::getY() const { return y; }
float Question4::getZ() const { return z; }

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Question4& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}