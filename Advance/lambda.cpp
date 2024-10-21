#include <iostream>
// Basic Lambda Function
int main() {
    auto add = [](int a, int b) {
        return a + b;
    };

    int result = add(5, 3);
    std::cout << "Sum: " << result << std::endl;  // Output: Sum: 8

    return 0;
}
