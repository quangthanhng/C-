#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout<< "Hay nhap so nguyen duong n: ";
	cin >> n;
	int k;
	cout <<"Hay nhap so mu: ";
	cin >> k;
	int sum = 1;
	for(int i = 1; i<= n; i++){
		sum += (i+1)*pow(k,i);
	}
	cout << sum;
	return 0;
}
