#include <iostream>
#include <vector>
#include "Lagrange.h"

void Lagrange() {
    int n = 6;
    std::vector<double> x = {0.43, 0.48, 0.55, 0.62, 0.70, 0.75};
    std::vector<double> y = {1.63597, 1.73234, 1.87686, 2.03345, 2.22846, 2.35973};
    double x_cur = 0.608;
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double P = 1;

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                P *= (x_cur - x[j]);
                P /= (x[i] - x[j]);
            }
        }

        result += P * y[i];
    }

    std::cout << result << "\n";
}