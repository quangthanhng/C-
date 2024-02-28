#include <iostream>
using namespace std;

int main() {
    int n, sum = 1;
    cout << "Nhap vao mot so nguyen: ";
    cin >> n;

    for(int i=n; i>0; i/=10) {
        sum *= i % 10;
    }
    cout << "Tich cac chu so cua so nguyen la: " << sum << endl;
    return 0;
}
