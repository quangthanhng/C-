#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	int x;
	cout << " Nhap so x: ";
	cin >> x;
	float sum = 1 + x;
	int t = x;
	int m = 1;
	for( int i = 3; i <= 2*n+1; i+= 2){
		t *= pow(x,2);
		m *= i*(i-1);
		sum += t / (float)m;
	}
	cout << fixed<< setprecision(1) << sum;
}
