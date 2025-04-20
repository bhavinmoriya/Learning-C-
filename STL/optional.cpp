#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b) {
    if (b == 0) {
        return std::nullopt;  // Return empty (no value) if division by zero
    }
    return a / b;
}

int main() {
    int x = 10;
    int y = 0;

    // Try to divide
    std::optional<int> result = divide(x, y);

    if (result) {
        std::cout << "Result: " << *result << std::endl;  // If a value exists
    } else {
        std::cout << "Division by zero!" << std::endl;  // If no value (std::nullopt)
    }

    return 0;
}
