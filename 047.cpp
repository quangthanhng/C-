# include <bits/stdc++.h>

using namespace std;

int main(){
	float s = 0;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s += sqrt( 1 + (1/(float)(i*i)) + (1/(float)(pow(i+1,2))));
	}
	cout << s;
	return 0;
}
