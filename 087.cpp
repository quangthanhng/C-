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
	for( int i = 0; i <= n; i++){
		s += pow(-1,i)*pow(x,2*i+1);
	}
	cout << s;
	return 0;
}
