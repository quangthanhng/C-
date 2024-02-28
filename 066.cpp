#include <iostream>

bool hasOddDigit(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    int n;
    std::cout << "Nhap so nguyen duong n: ";
    std::cin >> n;
    
    if (hasOddDigit(n)) {
        std::cout << "So nguyen duong n co ton tai chu so le." << std::endl;
    } else {
        std::cout << "So nguyen duong n khong ton tai chu so le." << std::endl;
    }
    
    return 0;
}

