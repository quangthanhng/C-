# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int dem;
	cout << " Nhap n:";
	cin >> n;
	if( n > 0 && n % 2 != 0){
	for( int i = 1; i <= n; i++){
		if( n % i == 0){
			if( i % 2 != 0){
				cout <<" Cac uoc so le cua n la: " << i << endl;
			}
		}
	}
		}else cout << " Khong co uoc so le cua n";
	return 0;
}
