#include <iostream>
// In this example, the lambda captures variables from the surrounding scope by reference, 
// meaning any changes inside the lambda will affect the original variables
int main() {
    int x = 10;
    int y = 20;

    auto modify = [&x, &y]() {
        x += 5;
        y += 10;
    };

    modify();
    std::cout << "Modified x: " << x << ", y: " << y << std::endl;  // Output: Modified x: 15, y: 30
    return 0;
}
