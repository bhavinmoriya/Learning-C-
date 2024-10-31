#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Polynomial
{
public:
    std::vector<double> coefficients;

    Polynomial(std::vector<double> coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;
    void print() const;
};

Polynomial Polynomial::operator+(const Polynomial &other) const
{
    size_t n = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(n, 0);

    for (size_t i = 0; i < n; ++i)
    {
        if (i < coefficients.size())
            result[i] += coefficients[i];
        if (i < other.coefficients.size())
            result[i] += other.coefficients[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial &other) const
{
    size_t n = coefficients.size() + other.coefficients.size() - 1;
    std::vector<double> result(n, 0);

    for (size_t i = 0; i < coefficients.size(); ++i)
    {
        for (size_t j = 0; j < other.coefficients.size(); ++j)
        {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(result);
}

void Polynomial::print() const
{
    for (int i = coefficients.size() - 1; i >= 0; --i)
    {
        if (coefficients[i] != 0)
        {
            std::cout << (coefficients[i] > 0 && i != coefficients.size() - 1 ? " + " : "")
                      << coefficients[i]
                      << (i > 0 ? "x^" + std::to_string(i) : "");
        }
    }
    std::cout << std::endl;
}
// Horner's Method
double evaluatePolynomial(const std::vector<double> &coefficients, double x)
{
    // double result = 0.0;
    double result = coefficients[coefficients.size() - 1];
    // Traverse coefficients from highest to lowest
    for (int i = coefficients.size() - 2; i >= 0; --i)
    {
        // std::cout<<"Hellow";
        result = result * x + coefficients[i];
    }
    return result;
}

std::vector<double> f(int n)
{
    std::vector<double> result = {1};
    int place = 0;
    while (place < (int)n)
    {
        result.push_back(result[place] / 4);
        // result.push_back(result[place]);
        result[place + 1] *= ((double)(2 * place + 2) * (2 * place + 1));
        result[place + 1] /= ((double)(place + 1) * (place + 1));
        place += 1;
    }
    return result;
}

std::vector<double> g(int n)
{
    std::vector<double> result = {pow(4, n)};
    int place = 0;
    while (place < (int)n)
    {
        result.push_back(result[place] / 4);
        // result.push_back(result[place]);
        result[place + 1] *= ((2 * place + 2) * (2 * place + 1));
        result[place + 1] /= ((place + 1) * (place + 1));
        place += 1;
    }
    return result;
}
int binom(int k)
{
    // Compute 2k choose k
    int result = 1;
    int place = 1;
    while (place < k + 1)
    {
        result *= ((double)(k + place) / place);
        // result *= (k + place);
        // result /= place;
        place += 1;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int n = std::stoi(argv[1]);
    // int powerof2 = std::stoi(argv[2]);
    std::vector<double> coeff = f(n);
    // std::vector<double> coeff = g(n);
    // Polynomial re({1});
    // evaluatePolynomial(re.coefficients,200);
    Polynomial result({0, 1});
    Polynomial poly1({0, 1, 0, -1}); // x(1-x^2)
    // poly1.print();
    Polynomial poly({1, 0, -1}); // 1-x^2

    // for (int i = 0; i < n + 1; i++)
    //     cout << coeff[i] << " and " << binom(i) / pow(4, i) << endl;

    result = result + (Polynomial({coeff[1]}) * poly1);
    // result = result * Polynomial({2});
    // result.print();
    for (int i = 2; i < n + 1; i++)
    {
        poly1 = poly1 * poly;
        result = result + (Polynomial({coeff[i]}) * poly1);
        // result = result * Polynomial({pow(4,i)});
        // result.print();
    }

    // Polynomial sum = poly1 + poly2;
    // Polynomial product = poly1 * poly2;
    // result = result * Polynomial({pow(2, powerof2)});
    std::cout << "f_" << n << "(x) = ";
    result.print();
    // int count = 0;
    // for (double i : result.coefficients)
    // {
    //     if (count % 2 != 0)
    //         std::cout << i << ", ";
    //     count += 1;
    // }
    double x;
    int iteration;
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the number of iteration: ";
    std::cin >> iteration;

    double value = evaluatePolynomial(result.coefficients, x);
    for (int i = 0; i < iteration - 1; i++)
    {
        value = evaluatePolynomial(result.coefficients, value);
    }

    std::cout << "The polynomial evaluated at x = " << x << " is " << value << std::endl;
    // poly.print();

    // std::cout << "Product: ";
    // product.print();

    return 0;
}
