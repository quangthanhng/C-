#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double n;
    cout << "Nhap vao gia tri cua n: ";
    cin >> n;
    double sum = 0;
    for(int i = 1; i <= n; i++){
       sum += 1/(double)(2*i);
    }
    cout << sum;
    return 0;
}