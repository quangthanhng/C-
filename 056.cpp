# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int s = 1;
	cout << " Nhap n:";
	cin >> n;
	if( n > 0 && n % 2 == 0){
	for( int i = 1; i <= n; i++){
		if( n % i == 0){
			if( i % 2 == 0){
				s *= i;
			}
		}
	}
	cout <<" Tich cac uoc chan cua n la: "<< s;
		}else cout << " Khong co uoc so chan cua n";
	return 0;
}
