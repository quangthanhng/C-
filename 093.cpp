#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout <<" Hay nhap vao so n: ";
	cin >> n;
	float s = 0;
	for(int i = 1; i <= n; i++){
		s = sqrt(2 + s);
	}
	cout << s;
	return 0;
}
