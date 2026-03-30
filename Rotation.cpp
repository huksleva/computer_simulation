#include "Rotation.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

void Rotation_method() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};

    for (int i = 0; i < n - 1; ++i) {
        for (int k = i + 1; k < n; ++k) {
            double cos_alpha = a[i][i] / std::sqrt(a[i][i] * a[i][i] + a[k][i] * a[k][i]);
            double sin_alpha = a[k][i] / std::sqrt(a[i][i] * a[i][i] + a[k][i] * a[k][i]);

            for (int j = i; j < n; ++j) {
                double new_a_i_j = a[i][j] * cos_alpha + a[k][j] * sin_alpha;
                double new_a_k_j = (-1) * a[i][j] * sin_alpha + a[k][j] * cos_alpha;
                a[i][j] = new_a_i_j;
                a[k][j] = new_a_k_j;
            }

            double new_b_i = b[i] * cos_alpha + b[k] * sin_alpha;
            double new_b_k = (-1) * b[i] * sin_alpha + b[k] * cos_alpha;
            b[i] = new_b_i;
            b[k] = new_b_k;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(3) << a[i][j] << " ";
        }

        std::cout << b[i] << "\n";
    }

    std::vector<double> x = std::vector<double>(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        double x_cur = b[i];

        for (int j = i + 1; j < n; ++j) {
            x_cur -= a[i][j] * x[j];
        }

        x_cur /= a[i][i];
        x[i] = x_cur;
    }

    std::cout << "result:" << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << " ";
    }

    std::cout << "\n";
}