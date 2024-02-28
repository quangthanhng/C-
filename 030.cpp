# include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	float s = 0;
	cout << " Nhap N: ";
	cin >> N;
	for ( int i = 1; i <= N; i++ ){
			s += (1/(2*(float)i));
	}
	cout << s;
	return 0;
}
