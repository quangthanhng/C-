#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int at = -2;
    int n, ahh;
    cout << " Nhap vao so n: ";
    cin >> n;
    for(int i = 2; i <= n; i++){
        ahh = 5* at + 2 * pow(3,i) - 6*pow(7,i) + 12;
        at = ahh;
    }
    cout << ahh;
    return 0;
}