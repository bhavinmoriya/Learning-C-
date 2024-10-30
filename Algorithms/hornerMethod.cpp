#include <iostream>
#include <vector>

double evaluatePolynomial(const std::vector<double>& coefficients, double x) {
    double result = 0.0;
    // Traverse coefficients from highest to lowest
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    // Define the polynomial P(x) = 3x^3 + 2x^2 + x + 5
    std::vector<double> coefficients = {5, 1, 2, 3};  // Corresponds to 3x^3 + 2x^2 + x + 5
    
    double x;
    std::cout << "Enter the value of x: ";
    std::cin >> x;

    double result = evaluatePolynomial(coefficients, x);
    std::cout << "The polynomial evaluated at x = " << x << " is " << result << std::endl;

    return 0;
}
