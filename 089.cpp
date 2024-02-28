#include <bits/stdc++.h>

using namespace std;
int ham(int n){
	int s = 0;
	for(int i = 1; i<= n; i++){
		s += i;
	}
	return s;
}

int main(){
	int n;
	float x;
	cout << "Hay nhap vao so nguyen n: ";
	cin >> n;
	float s = 0;
	for( int i = 1; i <= n; i++){
		s += pow(-1,i)*(float)pow(x,i)/ham(i);
	}
	cout << s;
	return 0;
}
