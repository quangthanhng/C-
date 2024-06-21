#include <iostream>

using namespace std;
int reverse(int n){
    int reverse_value = 0;
    for(int i = n; i > 0; i/= 10){
        reverse_value = ((i%10) + reverse_value * 10);
    }
    return reverse_value;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
