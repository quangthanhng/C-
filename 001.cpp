# include <bits/stdc++.h>

using namespace std;

int main(){
	float x1, x2, y1, y2;
	cout << "x1 = ";
	cin >> x1;
	cout << "x2 = ";
	cin >> x2;
	cout << "y1 = ";
	cin >> y1;
	cout << "y2 = ";
	cin >> y2;
	cout  << " Khoang cach giua chung la: "<< sqrt( pow((x1-x2),2) + pow((y1-y2),2));
	return 0;
}
