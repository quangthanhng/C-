# include <iostream>

using namespace std;

int main(){
	float x, x1, x2, x3, x4;
	cin >> x;
	x1 = pow(x,2);
	x2 = pow(x1,2);
	x3 = x2 * x1;
	x4 = x3 * x;
	cout << x4;
	return 0;
}