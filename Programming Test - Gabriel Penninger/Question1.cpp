#include "Question1.h"

// Explanation: I decided to use recursion for the implementation of the function.
// This is due to the fact that the recursive definition of the function is a more natural and intuitive approach.
// The argument could be made that an iterative solution would be better because of "stack depth management" and optimization. 
// However, with the given range of the problem being n (1 to 20), I decided that the difference in space would be negligible and recursion is just more elegant and cleaner :).


// Base case for F(0)
int Question1::F(int n) {
    if (n == 0) return 0;  // Base case: F(0) = 0
    return n + F(n - 1);    // Recursive case: F(n) = n + F(n-1)
}

// Function to print the results of F(0) to F(20)
void Question1::printResults() {

    // Loop through values from 0 to 20 and calculate F(n) for each
    for (int i = 0; i <= 20; ++i) {
        std::cout << "F(" << i << ") = " << F(i) << std::endl;
    }
}