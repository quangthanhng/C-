#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Hay nhap vao so nguyen n: ";
	cin >> n;
	int x;
	cout << "Hay nhap vao so x: ";
	cin >> x;
	float s = 0;
	float degit = 1;
	for(int i = 0; i<= n; i++){
		degit *= x + i;
		s += 1/(degit);
	}
	cout << s;
	return 0;
}
