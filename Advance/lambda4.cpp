#include <iostream>
// Lambda functions can also be generic, meaning they can accept any type, similar to template functions.
int main() {
    auto multiply = [](auto a, auto b) {
        return a * b;
    };

    std::cout << "3 * 4 = " << multiply(3, 4) << std::endl;            // Output: 3 * 4 = 12
    std::cout << "2.5 * 1.5 = " << multiply(2.5, 1.5) << std::endl;    // Output: 2.5 * 1.5 = 3.75

    return 0;
}
