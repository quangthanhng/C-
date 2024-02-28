#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cout <<" Hay nhap vao so n: ";
	cin >> n;
	float s = 0;
	for(int i = 1; i <= n; i++){
		s = pow(i+s,(1/(float)(i+1)));
	}
	cout << s;
	return 0;	
}	
