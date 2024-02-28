#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	cout << "Nhap so x: ";
	int x;
	cin >> x;
	int m = 0;
	float s = 0;
	int t = 1;
	for(int i = 1; i <= n; i++){
		m += i;
		t *= x;
		s += t/(float)(m);
	}
	cout << s;
	return 0;
}
