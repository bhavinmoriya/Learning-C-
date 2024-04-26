#include <iostream>
#include <string>
using namespace std;
class Complex
{
private:
    /* data */
    float real, imaginary;

public:
    Complex(float r, float i)
    {
        real = r;
        imaginary = i;
    }
    float getSum(Complex a, Complex b)
    {
        return a.real + b.real + a.imaginary + b.imaginary;
    }
    getDiff(Complex a, Complex b)
    {
        return a.real - b.real * a.imaginary - b.imaginary;
    }
    // ~Complex();
};

// Complex::Complex(/* args */)
// {
// }

// Complex::~Complex()
// {
// }

int main()
{
    Complex a(3, 4);
    Complex b(3, 6);
    cout << "Sum of a and b is:" << getSum(a, b);
    // cout << "Product of a and b is:" << getProduct(a, b);
    // cout << "Subtract of a and b is:" << getDiff(a, b);
    // cout << "Division of a by b is:" << getDivision(a, b);

    return 0;
}
