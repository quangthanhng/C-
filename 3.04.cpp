#include<iostream>
using namespace std;
int main(){
    int n, a, b;
    cin >> a >> b >> n;
    int sum = 0;
    if(a < 1 || b < 1 || a > 2000 || b > 2000 || n < 0 || n > 5){
        cout << " Nhap khong hop le";
    }else {
        for(int i = 1; i <= n; i++){
            sum += a * b;
            a++;
            b++;
        }
    }
    cout << sum;
}