#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = n; i > 0; i /= 10){
        sum += (i % 10);
    }
    cout << sum;
    return 0;
}