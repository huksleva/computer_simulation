#include "Gauss.h"
#include <vector>
#include <iostream>
#include <iomanip>

void Gauss() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};

    for (int k = 0; k < n - 1; ++k) {
        double a_k_k = a[k][k];

        for (int i = k; i < n; ++i) {
            a[k][i] /= a_k_k;
        }

        b[k] /= a_k_k;

        for (int i = k + 1; i < n; ++i) {
            double a_i_k = a[i][k];

            for(int j = k; j < n; ++j) {
                a[i][j] -= a_i_k * a[k][j];
            }

            b[i] -= a_i_k * b[k];
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


void Gauss_with_exception() {
    constexpr int N = 4; // размер матрицы (здесь она может быть только квадратной)
    int a[N][N] = {
        {-5, 7, 6, 5},
        {1, -12, 3, 4},
        {9, 0, 3, -1},
        {-4, -11, -3, -5}
    };

    int b[N] = { 23, 32, 33, 31 };











}

