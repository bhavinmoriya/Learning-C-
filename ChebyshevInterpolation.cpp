#include <iostream>
#include <vector>
#include <cmath>

// Function to be approximated
double f(double x) {
    return 1.0 / (1.0 + 25.0 * x * x);
}

// Generate Chebyshev nodes for the interval [-1, 1]
std::vector<double> generateChebyshevNodes(int n) {
    std::vector<double> nodes(n + 1);
    for (int i = 0; i <= n; ++i) {
        nodes[i] = cos(M_PI * (2 * i + 1) / (2 * (n + 1)));
    }
    return nodes;
}

// Evaluate the Lagrange basis polynomial L_k at point x
double lagrangeBasis(const std::vector<double>& nodes, int k, double x) {
    double result = 1.0;
    for (int j = 0; j < nodes.size(); ++j) {
        if (j != k) {
            result *= (x - nodes[j]) / (nodes[k] - nodes[j]);
        }
    }
    return result;
}

// Evaluate the Chebyshev interpolation polynomial at point x
double chebyshevInterpolation(const std::vector<double>& nodes, const std::vector<double>& values, double x) {
    double result = 0.0;
    for (int k = 0; k < nodes.size(); ++k) {
        result += values[k] * lagrangeBasis(nodes, k, x);//using Lagrange interpolation
        // result += values[k] * cos(k*acos(x)); //Chebyshev pol of 1st kind
    }
    return result;
}

int main() {
    int n = 200; // Degree of the interpolation polynomial

    // Step 2: Generate Chebyshev nodes
    std::vector<double> nodes = generateChebyshevNodes(n);

    // Step 3: Evaluate the function at Chebyshev nodes
    std::vector<double> values(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        values[i] = f(nodes[i]);
    }

    // Step 5: Evaluate the interpolation at various points and compare with the actual function
    int numPoints = 10;
    double x_min = -1.0;
    double x_max = 1.0;
    double dx = (x_max - x_min) / (numPoints - 1);

    std::cout << "x\tActual f(x)\tInterpolated f(x)" << std::endl;
    for (int i = 0; i < numPoints; ++i) {
        double x = x_min + i * dx;
        double actual = f(x);
        double interpolated = chebyshevInterpolation(nodes, values, x);
        std::cout << x << "\t" << actual << "\t" << interpolated << "\t"
        << actual-interpolated<<std::endl;
    }

    return 0;
}
