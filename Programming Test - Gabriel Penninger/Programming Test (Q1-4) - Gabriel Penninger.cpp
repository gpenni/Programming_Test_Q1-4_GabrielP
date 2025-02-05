// Programming Test - Gabriel Penninger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream> 
#include <string>
#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"

int main() {
    int choice;

    std::cout << "Select which question to output:\n";
    std::cout << "Enter your choice (1 to 4): ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::cout << "\nRunning Question 1:\n";
        // Test and output the result of Question 1
        Question1 q1;
        q1.printResults();
    }

    else if (choice == 2) {
        std::cout << "\nRunning Question 2:\n";
        // Test and output the result of Question 2
        Question2 q2;

        // Create vertices and triangles for Question 2
        Vertex v1(0, 0, 0), v2(1, 0, 0), v3(0, 1, 0);
        Color c1(1, 0, 0), c2(0, 1, 0), c3(0, 0, 1);
        Triangle t1(v1, v2, v3, c1, c2, c3);

        Vertex v4(1, 0, 0), v5(1, 1, 0), v6(0, 1, 0);
        Color c4(1, 1, 0), c5(0, 1, 1), c6(1, 0, 1);
        Triangle t2(v4, v5, v6, c4, c5, c6);

        q2.addTriangle(t1);
        q2.addTriangle(t2);

        std::cout << "Number of triangles: " << q2.getTriangles().size() << std::endl;
        for (size_t i = 0; i < q2.getTriangles().size(); ++i) {
            const Triangle& t = q2.getTriangles()[i];
            std::cout << "Triangle " << i + 1 << " normal: ("
                << t.normal.x << ", " << t.normal.y << ", " << t.normal.z << ")\n";
        }
    }

    else if (choice == 3) {
        std::cout << "\nRunning Question 3:\n";
        // Test and output the result of Question 3
        slow_string str1, str2;

        // User input
        std::cout << "Enter first string: ";
        std::cin >> str1;
        std::cout << "Enter second string: ";
        std::cin >> str2;

        // Print user input
        std::cout << "String 1: " << str1 << "\n";
        std::cout << "String 2: " << str2 << "\n";

        // Concatenation
        slow_string result = str1 + str2;
        std::cout << "Concatenated: " << result << "\n";

        // Comparison
        if (str1 == str2) {
            std::cout << "Strings are equal.\n";
        }
        else {
            std::cout << "Strings are not equal.\n";
        }

        // Length check
        std::cout << "Length of String 1: " << str1.length() << "\n";
        std::cout << "Length of String 2: " << str2.length() << "\n";
    }

    else if (choice == 4) {  
        std::cout << "\nRunning Question 4:\n";
        // Test and output the result of Question 4
    
        // Create vectors
        Question4 v1(3.0f, 4.0f, 5.0f);
        Question4 v2(1.0f, 2.0f, 3.0f);

        // Display vectors
        std::cout << "Vector 1: " << v1 << "\n";
        std::cout << "Vector 2: " << v2 << "\n";

        // Basic Operations
        std::cout << "Addition: " << v1 + v2 << "\n";
        std::cout << "Subtraction: " << v1 - v2 << "\n";
        std::cout << "Multiplication (by scalar 2): " << v1 * 2.0f << "\n";
        std::cout << "Division (by scalar 2): " << v1 / 2.0f << "\n";

        // Dot and Cross Product
        std::cout << "Dot Product: " << v1.dot(v2) << "\n";
        std::cout << "Cross Product: " << v1.cross(v2) << "\n";

        // Magnitude & Normalization
        std::cout << "Magnitude of v1: " << v1.magnitude() << "\n";
        std::cout << "Normalized v1: " << v1.normalized() << "\n";
    }

    else {
        std::cout << "Invalid choice! Please select 1, 2, 3, or 4.\n";
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file