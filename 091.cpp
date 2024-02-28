#include <bits/stdc++.h>

using namespace std;
int ham(int n){
	int degit = 1;
	int math = 1;
	n = 2*n;
	for(int i = n; i >= 1; i--){
		degit *= i;
	}
	return degit;
}

int main(){
	int n;
	float x;
	cout << "Hay nhap vao so nguyen n: ";
	cin >> n;
	cout << "Hay nhap vao so x: ";
	cin >> x;
	float s = -1;
	for( int i = 1; i <= n; i++){
		s += pow(-1,i+1)*(pow(x,2*i)/(ham(i)));
		}
		cout << s;
	return 0;
}
