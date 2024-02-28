# include <bits/stdc++.h>

using namespace std;

int main(){
	long long x;
	int s = 1;
	cout << " Nhap x: ";
	cin >> x;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 0; i <= n; i++){
		s *= (x + i);
	}
	cout << s;
	return 0;
}
