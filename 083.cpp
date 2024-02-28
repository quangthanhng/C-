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
	for(int i = 1; i<= n; i++){
		s += sin(pow(x,i));
	}
	cout << s;
	return 0;
}
