#include<iostream>
#include<cmath>

using namespace std;

float program_1(int x, int n){
    double sum = 1;
    for(int i = 1; i <= n; i++){
        sum += pow(x,i);
    }
    return sum;
}

float program_2(int x, int n){
    double sum = 1;
    for(int i = 2; i <= 2*n; i += 2){
        sum += pow(x,i);
    }
    return sum;
}

float giaithua(int n){
    double tich = 1;
    for(int i = 1; i <= n; i++){
        tich *= i;
    }
    return tich;
}

float program_3(int x, int n){
    double sum = 1;
    for(int i = 1; i <= n; i++){
        sum += pow(x,i)/(giaithua(i));
    }
    return sum;
}

int main(){
    int x, n;
    cin >> n >> x;
    cout << program_1(x,n) << endl;
    cout << program_2(x,n) << endl;
    cout << program_3(x,n) << endl;
}