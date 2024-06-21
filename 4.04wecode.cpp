#include <iostream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool IsPrime(int n){
    if(n <= 1) 
        return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// Hàm tính GCD của hai số
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int sum_common_prime(int a, int b){
    int gcd_value = gcd(a, b);
    int sum = 0;
    for(int i = 2; i <= gcd_value; i++){
        if(gcd_value % i == 0 && IsPrime(i)){
            sum += i;
        }
    }    
    return sum > 0 ? sum : -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << sum_common_prime(m, n) << endl;
}
