#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout <<" Hay nhap vao so n: ";
	cin >> n;
	float s = 0;
	for(int i = 2; i <= n; i++){
		s = pow(i+s,(1/(float)i));
	}	
	cout << s;
	return 0;
}	