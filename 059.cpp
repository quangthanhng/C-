#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Nhap vao mot so nguyen: ";
    cin >> n;

    for(int i=n; i>0; i/=10) {
        sum += 1;
    }

    cout << "So luong chu so cua so nguyen la: " << sum << endl;
    return 0;
}
