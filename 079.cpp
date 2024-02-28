#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout<< "Hay nhap so nguyen duong n: ";
	cin >> n;
	int sum = 0;
	int k = 1;
	for(int i = 1; i<= n; i++){
		k *= i;
		sum += i*k;
	}
	cout << sum;
	return 0;
}
