#include "DigitByDigit.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

void Digit_by_digit_method() {
    int n = 32;
    std::vector<double> q(n + 1);
    int l1;
    double k1, k2, k3, p, x0, y0, al0, al, x, y, x1;
    
    k1 = 1.0;
    k2 = k1;

    for (int i = 2; i < n; ++i) {
        p = 2.0;
        l1 = 2 * (i - 2);

        for (int l = 0; l <= l1; ++l) {
            p *= 0.5;
        }

        k2 *= (1.0 + p);
        k1 *= (1.0 + 1.0 / std::exp((2.0 * (i - 2)) * std::log(2.0)));
    }

    k2 = std::sqrt(k2);
    k1 = std::sqrt(k1);
    k3 = 1.0 / k2;

    q[1] = M_PI / 2.0;

    for (int i = 2; i < n; ++i) {
        p = 2.0;

        for (int l = 0; l <= (i - 2); ++l) {
            p *= 0.5;
        }

        q[i] = std::atan(p);
    }

    x0 = 1.0;
    y0 = 0.0;
    al0 = M_PI / 4.0;

    x0 *= k3;
    y0 *= k3;

    if (al0 > 0.0) {
        x = -y0;
        y = x0;
        al = al0 - q[1];
    } 
    else {
        x = y0;
        y = -x0;
        al = al0 + q[1];
    }

    for (int i = 2; i <= n; ++i) {
        p = 2.0;

        for (int l = 0; l <= i - 2; ++l) {
            p *= 0.5;
        }

        x1 = x;

        if (al > 0.0) {
            x = x - y * p;
            y = y + x1 * p;
            al = al - q[i];
        } else {
            x = x + y * p;
            y = y - x1 * p;
            al = al + q[i];
        }
    }

    std::cout << std::fixed << std::setprecision(5) << "cosa = " << x << "\n";
    std::cout << std::fixed << std::setprecision(5) << "sina = " << y << "\n";

}