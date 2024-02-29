# include <iostream>
# include <math.h>

using namespace std;

int main(){
	float x, x1, x2, x3;
	cin >> x;
	x1 = pow(x,2);
	x2 = pow(x1,2);
	x3 = x2 * x1;
	cout << x3;
	return 0;
}
