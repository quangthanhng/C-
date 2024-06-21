#include <iostream>

using namespace std;

// Hàm tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int x;
    cin >> x;

    if (x < 1 || x > 30) {
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    } else {
        int result = fibonacci(x);
        cout << result << endl;
    }

    return 0;
}
