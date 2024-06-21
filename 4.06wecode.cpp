#include<iostream>

using namespace std;

void input(int& n){
    cin >> n;
}

int input(){
    int m;
    cin >> m;
    return m;
}

int gcd(int m, int n){
    int gcd_value;
    for(int i = 1; i < m; i++){
        if(m % i == 0 && n % i == 0){
            gcd_value = i;
        }
    }
    return gcd_value;
}

int main() {
	int m, n;
	input(n);
	m=input();
	cout << gcd(m, n);
}
