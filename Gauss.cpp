#include "Gauss.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>

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


void Gauss2() {
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

        for (int i = k + 1; i < n; ++i) {
            double a_i_k = a[i][k];

            for(int j = k; j < n; ++j) {
                a[i][j] -= a_i_k * a[k][j] / a_k_k;
            }

            b[i] -= a_i_k * b[k] / a_k_k;
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

void swap_cols(std::vector<std::vector<double>> &a, int i, int j) {
    for (auto &row : a) {
        std::swap(row[i], row[j]);
    }
}

void swap_vars(std::vector<int> &indexes, int i, int j) {
    std::swap(indexes[i], indexes[j]);
}

void Gauss3_1() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};
    std::vector<int> indexes(n);
    std::iota(indexes.begin(), indexes.end(), 0);


    for (int k = 0; k < n - 1; ++k) {
        double a_max = a[k][k];
        int j = k;
        for (int i = k + 1; i < n; ++i) {
            if (a[k][i] > a_max) {
                a_max = a[k][i];
                j = i;
            }
        }

        swap_cols(a, k, j);
        swap_vars(indexes, k, j);

        double a_k_k = a[k][k];

        for (int i = k + 1; i < n; ++i) {
            double a_i_k = a[i][k];

            for(int j = k; j < n; ++j) {
                a[i][j] -= a_i_k * a[k][j] / a_k_k;
            }

            b[i] -= a_i_k * b[k] / a_k_k;
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
        std::cout << x[indexes[i]] << " ";
    }

    std::cout << "\n";
}

void swap_lines(std::vector<std::vector<double>> &a, std::vector<double> &b, int i, int j) {
    std::swap(a[i], a[j]);
    std::swap(b[i], b[j]);
}

void Gauss3_2() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};

    for (int k = 0; k < n - 1; ++k) {
        double a_max = a[k][k];
        int j = k;
        for (int i = k + 1; i < n; ++i) {
            if (a[i][k] > a_max) {
                a_max = a[i][k];
                j = i;
            }
        }

        swap_lines(a, b, k, j);

        double a_k_k = a[k][k];

        for (int i = k + 1; i < n; ++i) {
            double a_i_k = a[i][k];

            for(int j = k; j < n; ++j) {
                a[i][j] -= a_i_k * a[k][j] / a_k_k;
            }

            b[i] -= a_i_k * b[k] / a_k_k;
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

void swap_max_elem(std::vector<std::vector<double>> &a, std::vector<double> &b, int i, int j, int new_i, int new_j) {
    swap_cols(a, j, new_j);
    swap_lines(a, b, i, new_i);
}


void Gauss3_3() {
    int n = 4;
    std::vector<std::vector<double>> a = {
        {5, 7, 6, 5},
        {7, 10, 8, 7},
        {6, 8, 10, 9},
        {5, 7, 9, 10}
    };

    std::vector<double> b = {23, 32, 33, 31};
    std::vector<int> indexes(n);
    std::iota(indexes.begin(), indexes.end(), 0);


    for (int k = 0; k < n - 1; ++k) {
        double a_max = a[k][k];
        int new_i = k;
        int new_j = k;
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                if (a[i][j] > a_max) {
                    a_max = a[i][j];
                    new_i = i;
                    new_j = j;
                }
            }
        }

        swap_max_elem(a, b, k, k, new_i, new_j);
        swap_vars(indexes, k, new_j);

        double a_k_k = a[k][k];

        for (int i = k + 1; i < n; ++i) {
            double a_i_k = a[i][k];

            for(int j = k; j < n; ++j) {
                a[i][j] -= a_i_k * a[k][j] / a_k_k;
            }

            b[i] -= a_i_k * b[k] / a_k_k;
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
        std::cout << x[indexes[i]] << " ";
    }

    std::cout << "\n";
}