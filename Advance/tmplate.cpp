#include <iostream>
#include <string>

using namespace std;
template <typename T>
class Container {
private:
    T element;

public:
    Container(T e) : element(e) {}
    T getElement() const { return element; }
};

int main() {
    Container<int> intContainer(123);
    Container<std::string> stringContainer("Hello");
    Container<double> doubleContainer(1.54654);
    Container<char> charContainer('A');
    Container<bool> boolContainer(true);

    std::cout << intContainer.getElement() << "\n"; // Output: 123
    std::cout << stringContainer.getElement() << "\n"; // Output: Hello
    std::cout << doubleContainer.getElement() << "\n";
    std::cout << charContainer.getElement() << "\n";
    std::cout << boolContainer.getElement() << "\n";
    
    return 0;
}
