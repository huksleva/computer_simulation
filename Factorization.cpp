#include "Factorization.h"
#include <vector>
#include <iostream>
#include <iomanip>

void Triangular_factorization() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};

    std::vector<double> x = std::vector<double>(n, 0);
    std::vector<std::vector<double>> l = std::vector<std::vector<double>>(n, std::vector<double>(n, 0));
    std::vector<std::vector<double>> r = std::vector<std::vector<double>>(n, std::vector<double>(n, 0));

    for (int i = 0; i < n; ++i) {
        r[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        l[i][0] = a[i][0];
    }

    for (int i = 1; i < n; ++i) {
        r[0][i] = a[i][0] / l[0][0];
    }

    for (int i = 1; i < n; ++i) {
        double sum_lr = 0;

        for (int j = 0; j < i; ++j) {
            sum_lr += l[i][j] * r[j][i];
        }

        l[i][i] = a[i][i] - sum_lr;
        sum_lr = 0;
        
        for (int t = i + 1; t < n; ++t) {
            for (int j = 0; j < i; ++j) {
                sum_lr += l[t][j] * r[j][i];
            }

            l[t][i] = a[t][i] - sum_lr;
            sum_lr = 0;

            for (int j = 0; j < i; ++j) {
                sum_lr += l[i][j] * r[j][t];
            }

            r[i][t] = (a[i][t] - sum_lr) / l[i][i];
            sum_lr = 0;
        }
    }

    std::cout << "Matrix L:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(3) << l[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::cout << "Matrix R:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(3) << r[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::vector<double> z = std::vector<double>(n, 0);

    z[0] = b[0] / l[0][0];

    for (int i = 1; i < n; ++i) {
        double sum_lz = 0;

        for (int j = 0; j < i; ++j) {
            sum_lz += l[i][j] * z[j];
        }

        z[i] = (b[i] - sum_lz) / l[i][i];
    }

    std::cout << "Vector Z:" << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << z[i] << " ";
    }

    std::cout << "\n";

    x[n - 1] = z[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        double sum_rx = 0;

        for (int j = i + 1; j < n; ++j) {
            sum_rx += r[i][j] * x[j];
        }

        x[i] = (z[i] - sum_rx);
    }

    std::cout << "Vector X:" << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << " ";
    }

    std::cout << "\n";
}
