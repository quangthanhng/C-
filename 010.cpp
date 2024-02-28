# include <bits/stdc++.h>

using namespace std;

int main(){
	float x1,x2,x3,y1,y2,y3,a,b,c;
	cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
	a = sqrt(pow((x1-x2),2)+ pow((y1-y2),2));
	b = sqrt(pow((x1-x3),2)+ pow((y1-y3),2));
	c = sqrt(pow((x3-x2),2)+ pow((y3-y2),2));
	cout << " Chu vi tam giac la: " << a + b + c;
	return 0;
}
