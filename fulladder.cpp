#include <iostream>

// Function to perform full addition for 1-bit
void fullAdder(bool a, bool b, bool cin, bool &sum, bool &cout) {
    // Calculate sum
    sum = a ^ b ^ cin;
    
    // Calculate carry-out
    cout = (a & b) | (b & cin) | (cin & a);
}

// Function to add two 4-bit numbers
void addFourBitNumbers(bool a[4], bool b[4], bool cin, bool sum[4], bool &cout) {
    // Initialize carry-in for the first full adder
    bool carryIn = cin;
    
    // Iterate over each bit of the input numbers
    for (int i = 3; i >= 0; --i) {
        // Perform full addition for each bit
        fullAdder(a[i], b[i], carryIn, sum[i], carryIn);
    }
    
    // Set the carry-out after the last full adder
    cout = carryIn;
}

int main() {
    // Input bits for two 4-bit numbers
    bool a[4], b[4];
    // Output bits for the sum of two 4-bit numbers
    bool sum[4];
    // Carry-in bit for the addition
    bool cin;
    // Carry-out bit for the addition
    bool cout;

    // Get input bits from user
    std::cout << "Enter two 4-bit numbers (a and b): ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        std::cin >> b[i];
    }
    std::cout << "Enter carry-in bit: ";
    std::cin >> cin;

    // Perform addition of two 4-bit numbers
    addFourBitNumbers(a, b, cin, sum, cout);

    // Display the result
    std::cout << "Sum: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << sum[i];
    }
    std::cout << std::endl;
    std::cout << "Carry-out: " << cout << std::endl;

    return 0;
}
