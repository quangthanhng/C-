#include <iostream>
#include <iomanip>

double giaithua(int n) {
    double value = 1;
    for (int i = 2; i <= n; ++i) {
        value *= i;
    }
    return value;
}

double ham_x(double x) {
    double result = 0;
    double term = x;
    double x_squared = x * x;
    int sign = 1;
    int n = 1;

    while (std::abs(term) >= 0.00001) {
        result += term;
        term *= -x_squared / ((n + 1) * (n + 2));
        n += 2;
    }

    return result;
}

int main() {
    double x;
    std::cin >> x;

    double a = ham_x(x);

    std::cout << std::fixed << std::setprecision(4) << a << std::endl;

    return 0;
}
