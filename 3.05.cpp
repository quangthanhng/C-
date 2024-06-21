#include<iostream>
#include<cmath>
using namespace std;

float program_1(int n){
    float sum = 0;
    for(int i = 1; i <= n; i++){
        sum += pow(i,i);
    }
    return sum;
}

float program_2(int n){
    float sum = 0;
    float multiple = 1;
    for(int i = 1; i <= n; i++){
        multiple *= i;
        sum += multiple;
    }
    return sum;
}

float program_3(int n){
    float sum = 0;
    float multiple = 0;
    for(int i = 1; i <= n; i++){
        multiple += i;
        sum += 1/(float) multiple;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    float a = program_1(n);
    cout << a << endl;
    float b = program_2(n);
    cout << b << endl;
    float c = program_3(n);
    cout << c << endl;
    return 0;
}