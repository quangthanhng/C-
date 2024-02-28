#include <bits/stdc++.h>

using namespace std;
int ham(int n){
	int degit = 1;
	for(int i = 1; i<= n; i++){
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
	float s = 0;
	for( int i = 1; i <= n; i++){
		s += pow(-x,i)/(float)(ham(i));
	}
	cout << s;
	
	return 0;
}
