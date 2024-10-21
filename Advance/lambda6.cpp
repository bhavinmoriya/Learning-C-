#include <iostream>
#include<complex>
// If a lambda's return type is ambiguous or complex, you can specify the return type explicitly:
int main() {
    auto divide = [](int a, int b) -> double  {
        return static_cast<double>(a) / b;
    };

    std::cout << "10 / 3 = " << divide(10, 3) << std::endl;  // Output: 10 / 3 = 3.33333
    return 0;
}
