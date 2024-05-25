#include <iostream>
#include <stdexcept>

void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    std::cout << "Result: " << a / b << "\n";
}

int main() {
    try {
        divide(10, 0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
