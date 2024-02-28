# include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	float s = 0;
	cout << " Nhap N: ";
	cin >> N;
	for ( int i = 0; i <= N; i++ ){
			s += (float)(2*i + 1)/(2*i + 2);
	}
	cout << s;
	return 0;
}
