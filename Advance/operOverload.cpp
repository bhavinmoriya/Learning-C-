#include <iostream>
#include <string>

using namespace std;
class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    Complex operator*(const Complex& other) const {
        return Complex(real*other.real - imag*other.imag, imag*other.real + real*other.imag);
    }
    
    

    void display() const {
        std::cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex c1(1.0, 2.0), c2(2.0, 3.0);
    Complex c3 = c1 + c2;
    
    Complex c4 = c1 * c3;
    c3.display();
    c4.display();
    return 0;
}
