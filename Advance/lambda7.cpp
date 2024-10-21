#include <iostream>
// You can use = to capture all variables by value, and & to capture all variables by reference.
int main() {
    int a = 5, b = 10;
    
    auto captureAllByValue = [=]() {
    // a+=3;
        std::cout << "a: " << a << ", b: " << b << std::endl;
    };

    captureAllByValue();  // Output: a: 5, b: 10
    // std::cout << "a: " << a << ", b: " << b << std::endl;
    return 0;
}
