# include <bits/stdc++.h>

using namespace std;

int main(){
	int s = 0;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s += pow(i,3);
	}
	cout << s;
	return 0;
}
