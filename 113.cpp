#include<iostream>
using namespace std;

int main(){
    int at = 2;
    int ahh, n;
    cout << " Nhap vao so n: ";
    cin >> n;
    for(int i = 2; i <= n; i++){
        ahh = at + 2*i + 1;
        at = ahh;
    }
    cout << ahh;
    return 0;
}