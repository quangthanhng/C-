#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout <<" Hay nhap vao so n: ";
	cin >> n;
	float s = 0;
	for(int i = n; i >= 1; i--){
		s = sqrt(i + s);
	}
	cout << s;
	return 0;
}	
