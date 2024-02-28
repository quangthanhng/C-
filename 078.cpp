#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout<< "Hay nhap so nguyen duong n: ";
	cin >> n;
	int x;
	cout <<"Hay nhap so nguyen x: ";
	cin >> x;
	int sum = 1;
	for(int i = 1; i<= n; i++){
		sum += pow(x,i);
	}
	cout << sum;
	return 0;
}
