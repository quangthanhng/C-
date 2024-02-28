# include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	float s = 0;
	cout << " Nhap N: ";
	cin >> N;
	for ( int i = 1; i <= N; i++ ){
			s += (1/(float)(i*( i + 1 )));
	}
	cout << s;
	return 0;
}
