#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// Function to multiply two polynomials
std::vector<int> multiplyPolynomials(const std::vector<int> &A, const std::vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    std::vector<int> result(m + n - 1, 0);

    // Multiply every term of A with every term of B
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i + j] += A[i] * B[j];
        }
    }

    return result;
}

int nearest(double x)
{
    return (x - floor(x) < .5) ? floor(x) : ceil(x);
}

void modReduction(std::vector<int> &poly, int N)
{
    int n = poly.size();
    for (int i = 0; i < N; ++i)
    {
        int j = i + N, sign = -1;
        while (j < n)
        {
            poly[i] += (sign * poly[j]);
            j += N;
            sign *= -1;
        }
    }
}

// Function to print a polynomial
void printPolynomial(const std::vector<int> &poly, int n)
{

    for (int i = 0; i < n; ++i)
    {
        std::cout << poly[i];
        if (i != 0)
        {
            std::cout << "x^" << i;
        }
        if (i != n - 1)
        {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    // Example polynomials A(x) and B(x)
    int N = 4;
    std::vector<int> A = {3, 2, 5}; // 3 + 2x + 5x^2
    std::vector<int> B = {5, 1, 2}; // 5 + 1x + 2x^2

    std::cout << "Polynomial A: ";
    printPolynomial(A, A.size());
    std::cout << "Polynomial B: ";
    printPolynomial(B, B.size());

    std::vector<int> result = multiplyPolynomials(A, B);

    std::cout << "Resultant Polynomial: ";
    printPolynomial(result, result.size());
    std::cout << string(26, '*') << endl;
    std::cout << "Reduction modulo X^" << N << "+1\n"
              << string(26, '*');
    modReduction(result, N);
    std::cout << "\nResultant Polynomial: ";
    printPolynomial(result, N);

    return 0;
}
