#include <iostream>

using namespace std;

// Hàm đệ quy để tính số đảo ngược
int reverseHelper(int n, int result) {
    if (n == 0)
        return result;
    result = result * 10 + (n % 10);
    return reverseHelper(n / 10, result);
}

// Hàm chính để gọi hàm đệ quy
int reverse(int n) {
    return reverseHelper(n, 0);
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}
