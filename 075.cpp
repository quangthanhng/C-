#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	int x;
	cout << " Nhap so x: ";
	cin >> x;
	float sum = 1;
	int t = 1;
	int m = 1;
	for( int i = 2; i <= n; i+= 2){
		t *= pow(x,2);
		m *= i*(i-1);
		sum += t / (float)m;
	}
	cout << sum;
}
