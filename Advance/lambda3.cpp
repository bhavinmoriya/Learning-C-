#include <iostream>
// In this example, the lambda captures variables from the surrounding scope by value (making a copy of the captured variables)
int main() {
    int x = 10;
    int y = 20;

    auto sum = [x, y]() {


        return x + y;
    };

    std::cout << "Sum: " << sum() << std::endl;  // Output: Sum: 30

    return 0;
}
