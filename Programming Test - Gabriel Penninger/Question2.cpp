#include "Question2.h"
#include <cmath>
#include <iostream>

// Constructor for Triangle to calculate normal
Triangle::Triangle(const Vertex& v1, const Vertex& v2, const Vertex& v3,
    const Color& c1, const Color& c2, const Color& c3)
    : vertices{ v1, v2, v3 }, colors{ c1, c2, c3 } {

    // Calculate the normal (cross product of two edges)
    Vertex edge1 = vertices[1] - vertices[0];
    Vertex edge2 = vertices[2] - vertices[0];

    normal = edge1.cross(edge2);

    // Normalize the normal
    normal.normalize();
}

// Adds a triangle to the list
void Question2::addTriangle(const Triangle& triangle) {
    triangles.push_back(triangle);
}

// Returns a constant reference to the list of triangles
const std::vector<Triangle>& Question2::getTriangles() const {
    return triangles;
}

void Question2::printResults() const {
    std::cout << "Number of triangles: " << triangles.size() << std::endl;

    for (size_t i = 0; i < triangles.size(); ++i) {
        const Triangle& triangle = triangles[i];
        std::cout << "Triangle " << i + 1 << " normal: ("
            << triangle.normal.x << ", "
            << triangle.normal.y << ", "
            << triangle.normal.z << ")" << std::endl;
    }
}