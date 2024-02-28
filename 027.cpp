# include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	int s = 0;
	cout << " Nhap N: ";
	cin >> N;
	for ( int i = 1; i <= N; i++ ){
			s += i;
	}
	cout << s;
	return 0;
}
