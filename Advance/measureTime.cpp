#include <iostream>
#include <chrono>
#include <functional>  // To use std::function

// Function to measure the time taken by any callable block of code
void measureExecutionTime(const std::function<void()>& codeBlock, const std::string& taskName) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Execute the code block
    codeBlock();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    // Output the execution time
    std::cout << "Time taken by " << taskName << ": " << duration.count() << " ms" << std::endl;
}

void someComputation() {
    for (int i = 0; i < 1000000; i++) {
        int x = i * 2;
    }
}

int main() {
    // Timing a specific code block using a lambda
    measureExecutionTime([]() {
        for (int i = 0; i < 1000000; i++) {
            int x = i * 2;
        }
    }, "Loop 1 million iterations");

    // Timing another code block
    measureExecutionTime([]() {
        for (int i = 0; i < 500000; i++) {
            int x = i * 2;
        }
    }, "Loop 500 thousand iterations");

    measureExecutionTime(someComputation, "Some Computation");

    return 0;
}
