#include <iostream>

using namespace std;

int input(int& n){
    cin >> n;
    return n;
}

int sum(int n, int& s){
    if(n == 0){
        return 0;
    }
    s += n % 10;
    return sum(n / 10, s);
}

int main() {
    int n, s=0;
    input(n);
    sum(n, s);
    cout << s;
}
