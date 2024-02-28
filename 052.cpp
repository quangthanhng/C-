# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int dem = 0;
	cout << " Nhap n:";
	cin >> n;
	for( int i = 1; i <= n; i++){
		if( n % i == 0){
			dem += 1;
		}
	}
	cout<< " So luong uoc so cua n la: "<< dem;
	return 0;
}
