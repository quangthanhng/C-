# include <bits/stdc++.h>

using namespace std;

int main(){
	float s = 1;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s *= (1 + 1/(float) (i*i));
	}
	cout << s;
	return 0;
}
