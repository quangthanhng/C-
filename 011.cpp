# include <bits/stdc++.h>

using namespace std;

int main(){
	float x1,x2,x3,y1,y2,y3,a,b,c,P;
	cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
	a = sqrt(pow((x1-x2),2)+ pow((y1-y2),2));
	b = sqrt(pow((x1-x3),2)+ pow((y1-y3),2));
	c = sqrt(pow((x3-x2),2)+ pow((y3-y2),2));
	P = (a + b + c)/2;
	cout << " Dien tich tam giac la: " << P*(P-a)*(P-b)*(P-c);
	return 0;
}
