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

std::vector<int> addingPolynomials(const std::vector<int> &A, const std::vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    int M = ((m <= n) ? n : m);
    std::vector<int> result(M, 0);

    // Multiply every term of A with every term of B
    for (int i = 0; i < M; ++i)
    {
        if (i >= m)
            result[i] += B[i];
        else if (i >= n)
            result[i] += A[i];
        else
            result[i] += A[i] + B[i];
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
void deltaM(std::vector<int> &A, int &delta)
{
    for (int i = 0; i < A.size(); ++i)
    {
        A[i] *= delta;
    }
}
int main()
{
    // Example polynomials A(x) and B(x)
    int q = 64, p = 4, k = 2, N = 4;
    int delta = q / p;
    // std::vector<int> A = {3, 2, 5}; // 3 + 2x + 5x^2
    // std::vector<int> B = {5, 1, 2}; // 5 + 1x + 2x^2
    std::vector<int> A0 = {17, -2, -24, 9}; // 17 + 2x-24x^2+9x^3
    std::vector<int> A1 = {-14, 0, -1, 21}; //
    A0 = {-8, 15, 3, -30};
    A1 = {23, -16, 27, -4};
    std::vector<int> S0 = {0, 1, 1}; //
    std::vector<int> S1 = {1, 0, 1, 1};
    std::vector<int> m1 = {-2, 1, 0, -1};
    std::vector<int> m2 = {0, 1, 1, -2};
    std::vector<int> e1 = {-1, 1, 0, 1};
    std::vector<int> e2 = {0, 1, -1, -1};

    std::vector<int> result = multiplyPolynomials(A0, S0);
    result = addingPolynomials(result, multiplyPolynomials(A1, S1));
    deltaM(m2, delta);
    printPolynomial(e1, e1.size());
    result = addingPolynomials(result, m2);
    result = addingPolynomials(result, e2);

    // printPolynomial(result, result.size());
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
