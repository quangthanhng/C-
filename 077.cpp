#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout<< "Hay nhap so nguyen duong n: ";
	cin >> n;
	int k;
	cout <<"Hay nhap so mu: ";
	cin >> k;
	int sum = 0;
	for(int i = 1; i<= n; i++){
		sum += pow(i,k);
	}
	cout << sum;
	return 0;
}
