#include <iostream>
#include <random>
#include <array>

int main() {
    // Create a random device and a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution that produces 0 or 1
    std::uniform_int_distribution<> dis(0, 1);

    // Create an array of booleans of length 3
    int size=16;
    bool boolArray[size];

    // Fill the array with random booleans
    for (int i = 0; i < size; ++i) {
        boolArray[i] = dis(gen);
    }

    // Print the array
    for (bool b : boolArray) {
        std::cout << b << " ";
    }
    std::cout << std::endl;

    return 0;
}
