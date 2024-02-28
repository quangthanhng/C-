#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
	int result = 1;
	for( int i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}
	int main(){
		int n;
		cout << " Hay nhap so nguyen duong n: ";
		cin >> n;
		int sum = 0;
			for( int i = 1; i <= n; i++){
				sum += factorial(i);
			}
		cout << " Tong giai thua tu 1 toi n la: "<< sum;
			return 0;
	}
