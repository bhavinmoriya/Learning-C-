#include <iostream>
#include <cmath>  // For abs() and pow()

using namespace std;



// Function to perform Goldschmidt's division
double goldschmidt_division(double dividend, double divisor, int max_iterations = 50) {
    // Step 1: Initial approximation of the reciprocal of the divisor
    cout << "Choose the reciprocal in a way that 0< divisor * reciprocal <2 "<<endl<<"Reciprocal:";
    double reciprocal;
    
    cin>>reciprocal;

    // Initial quotient estimate
    double quotient = dividend * reciprocal;

    // Refinement loop: iteratively refine the quotient
    for (int i = 0; i < max_iterations; i++) {
        // Compute correction factor: f_i = 2 - (b * r_i)
        double correction_factor = 2.0 - (divisor * reciprocal);

        // Update the reciprocal of the divisor: r_{i+1} = r_i * f_i
        reciprocal *= correction_factor;

        // Update the quotient estimate: q_{i+1} = q_i * f_i
        quotient *= correction_factor;

        // Print the intermediate results for each iteration
        cout << "Iteration " << i+1 << ": Quotient = " << quotient << ", Reciprocal = " << reciprocal << endl;
        
        // If the correction factor is close to 1, break the loop
        if (abs(correction_factor - 1.0) < 1e-10) {
            break;
        }
    }

    return quotient;
}

int main() {
    double dividend, divisor;
    
    // Input the dividend and divisor
    cout << "Enter the dividend: ";
    cin >> dividend;
    
    cout << "Enter the divisor: ";
    cin >> divisor;
    
    // Ensure the divisor is non-zero
    if (divisor == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return -1;
    }
    
    // Perform Goldschmidt's division
    double result = goldschmidt_division(dividend, divisor);

    // Output the final result
    cout << "Result of " << dividend << " / " << divisor << " = " << result << endl;
    
    return 0;
}
