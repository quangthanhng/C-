# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int s = 1;
	cout << " Nhap n:";
	cin >> n;
	for( int i = 1; i <= n; i++){
		if( n % i == 0){
			s *= i;
		}
	}
	cout<< "Tich cac uoc so cua n la: "<< s;
	return 0;
}
