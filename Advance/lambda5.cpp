#include <iostream>
#include <functional>
// You can pass a lambda as a parameter to a function that takes a callable (like std::function or a template function).
void applyFunction(const std::function<int(int, int)>& func, int x, int y) {
    std::cout << "Result: " << func(x, y) << std::endl;
}

int main() {
    applyFunction([](int a, int b) { return a + b; }, 5, 3);  // Output: Result: 8
    return 0;
}
