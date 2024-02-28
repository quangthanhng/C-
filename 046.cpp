# include <bits/stdc++.h>

using namespace std;

int main(){
	float s = 0;
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s += 1/(float)((i + 1) * sqrt(i)+ i * sqrt(i + 1));	
	}
	cout << s;
	return 0;
}
