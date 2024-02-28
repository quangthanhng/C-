# include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	float s = 0;
	cout << " Nhap N: ";
	cin >> N;
	for ( int i = 0; i <= N; i++ ){
			s += (1/(float)(2*i + 1));
	}
	cout << s;
	return 0;
}
