#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	int x;
	cout << " Nhap so x: ";
	cin >> x;
	float sum = 0;
	int t = 1;
	int m = 1;
	for( int i = 1; i <= n; i++){
		t *= x;
		m *= i;
		sum += t / (float)m;
	}
	cout << sum;
}
