# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int s = 1;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s *= i;
	}
	cout << s;
	return 0;
}
