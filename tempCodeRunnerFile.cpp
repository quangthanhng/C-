#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    float sum = 1;
    for(int i = 1; i <= n; i++){
        sum += pow(-1, i)/(float)(2*i+1);
    }
    cout << sum*4;
    return 0;
}