#include <iostream>

double calculate_S(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

int main() {
    int n;
    std::cout << "Nhap gia tri n: ";
    std::cin >> n;

    double result = calculate_S(n);
    std::cout << "Gia tri cua S(" << n << ") là " << result << " voi do chính xác 10^(-6)." << std::endl;

    return 0;
}

