#include <iostream>

int main() {
    int a = 5, b = 10;
    
    auto captureAllByReference = [&]() {
        a += 10;
        b += 20;
        std::cout << "Modified a: " << a << ", b: " << b << std::endl;
    };

    captureAllByReference();  // Output: Modified a: 15, b: 30
    return 0;
}
