#include <iostream>

// Lambda with No Parameters
int main() {
    auto sayHello = []() {
        std::cout << "Hello, World!" << std::endl;
    };

    sayHello();  // Output: Hello, World!
    return 0;
}
