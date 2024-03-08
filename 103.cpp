#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    double n;
    cout << "Nhap vao gia tri cua n: ";
    cin >> n;
    double sum = 0;
    for(int i = 0; i <= n; i++){
       sum += 1/(double)((2*i)+1);
    }
    cout << sum;
    return 0;
}