#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	cout << " Hay nhap so n: ";
	cin >> n;
	cout << " Hay nhap so x: ";
	cin >> x;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += pow(x,i);
	}
	cout << sum;
	return 0;
}
