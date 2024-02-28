#include <bits/stdc++.h>

using namespace std;

bool containsOddDegit(int n){
	for( int i = n; n > 0; n/= 10){
		int digit = n%10;
		if( digit % 2 != 0){
			return true;
		}
	}
	return false;
}
	int main(){
		int n;
		cout << " Nhap so nguyen duong n: ";
		cin >> n;
		if(containsOddDegit(n)){
			cout << " Co ton tai chu so le";
		}else cout << " Khong ton tai chu so le";
		return 0;
	}
	
