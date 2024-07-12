#include <iostream>
//#include <algorithm> // for std::min

unsigned long long binomialCoefficient(int n, int r) {
    if (r > n) return 0; // If r is greater than n, binomial coefficient is 0
    if (r == 0 || r == n) return 1; // If r is 0 or n, binomial coefficient is 1

    // Since C(n, r) = C(n, n-r), take the smaller value for fewer iterations
    r = std::min(r, n - r);

   // unsigned long long result = 1;

    // Calculate the binomial coefficient using the multiplicative formula
    /*for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
*/
    return binomialCoefficient(n-1,  r-1)+binomialCoefficient(n-1, r);
}

int main() {
    int n = 20;
    int r = 10;
    std::cout << "C(" << n << ", " << r << ") = " << binomialCoefficient(n, r) << std::endl;

    return 0;
}
