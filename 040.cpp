# include <bits/stdc++.h>

using namespace std;

int main(){
	float s = 0;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s += i*(i+1);
	}
	cout << s;
	return 0;
}
