#ifndef QUESTION2_H
#define QUESTION2_H

#include <vector>
#include <iostream>

struct Vertex {
    float x, y, z;

    // Constructor to initialize a Vertex
    Vertex(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Operator for vector subtraction
    Vertex operator-(const Vertex& other) const {
        return Vertex(x - other.x, y - other.y, z - other.z);
    }

    // Cross product between two vertices
    Vertex cross(const Vertex& other) const {
        return Vertex(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Normalize the vertex
    void normalize() {
        float length = std::sqrt(x * x + y * y + z * z);
        if (length > 0) {
            x /= length;
            y /= length;
            z /= length;
        }
    }
};

struct Color {
    float r, g, b;

    Color(float r = 0, float g = 0, float b = 0) : r(r), g(g), b(b) {}
};

class Triangle {
public:
    Vertex vertices[3];
    Color colors[3];
    Vertex normal;

    // Constructor for Triangle to calculate normal
    Triangle(const Vertex& v1, const Vertex& v2, const Vertex& v3,
        const Color& c1, const Color& c2, const Color& c3);
};

class Question2 {
private:
    std::vector<Triangle> triangles;

public:
    // Adds a triangle to the list
    void addTriangle(const Triangle& triangle);

    // Returns a constant reference to the list of triangles
    const std::vector<Triangle>& getTriangles() const;

    // Function to print all triangles and their normals
    void printResults() const;
};

#endif 