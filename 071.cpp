#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	cout << " Hay nhap so n: ";
	cin >> n;
	cout << " Hay nhap so x: ";
	cin >> x;
	int sum = 0;
	for(int i = 0; i <= n; i++){
		sum += pow(x,2*i+1);
	}
	cout << sum;
	return 0;
}
