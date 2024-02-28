#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	float x;
	cout << "Hay nhap vao so nguyen n: ";
	cin >> n;
	cout << " Hay nhap vao so x: ";
	cin >> x;
	float s = 0;
	float t = x;
	for( int i = 1; i <= n; i++){
		t = sin(t);
		s += t;
	}
	cout << s;
	return 0;
}
