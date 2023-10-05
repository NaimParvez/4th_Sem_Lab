#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x * x - 2 * x - 5;
}

double false_position(double a, double b, double tol, int max_iterations) {
    double x, error;

    for (int n = 1; n <= max_iterations; ++n) {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));
        error = fabs(x - a);

        cout << n << "\t" << a << "\t" << b << "\t" << x << "\t" << f(x) << "\t" << error << endl;

        if (error <= tol)
            return x;

        if (f(x) * f(a) < 0)
            b = x;
        else
            a = x;
    }

    return -1.0; // Return -1 to indicate failure to converge
}

int main() {
    double a, b, tol;
    int max_iterations = 1000; // Maximum number of iterations for both methods

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter the tolerance (e.g., 0.0002): ";
    cin >> tol;

    if (f(a) * f(b) >= 0) {
        cout << "The chosen bounds do not have opposite signs. Bisection and false position methods may not converge." << endl;
        return 1;
    }

    int choice;
    cout << "Choose a method:" << endl;
    cout << "1. Bisection" << endl;
    cout << "2. False Position" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "n\t  a\t\t  b\t\t  x\t\t  f(x)\t\t  Error" << endl;
        cout << "--------------------------------------------------------" << endl;

        // Bisection method
        double x_bisection, error_bisection;
        for (int n = 1; n <= max_iterations; ++n) {
            x_bisection = (a + b) / 2.0;
            error_bisection = fabs(b - a) / 2.0;

            cout << n << "\t" << a << "\t" << b << "\t" << x_bisection << "\t" << f(x_bisection) << "\t" << error_bisection << endl;

            if (error_bisection <= tol)
                break;

            if (f(x_bisection) * f(a) < 0)
                b = x_bisection;
            else
                a = x_bisection;
        }

        cout << "--------------------------------------------------------" << endl;
        cout << "Approximate root using bisection: " << x_bisection << endl;
    } else if (choice == 2) {
        cout << "n\t  a\t\t  b\t\t  x\t\t  f(x)\t\t  Error" << endl;
        cout << "--------------------------------------------------------" << endl;

        // False position method
        double x_false_position = false_position(a, b, tol, max_iterations);

        if (x_false_position != -1.0) {
            cout << "Approximate root using false position: " << x_false_position << endl;
        } else {
            cout << "False position method did not converge within the maximum number of iterations." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}