#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	int m = 0;
	float sum = 0;
	for(int i = 1; i <= n; i++){
		m += i;
		sum += 1/(float)(m);
	}
	cout << sum;
	return 0;
}
