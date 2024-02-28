#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Nhap vao mot so nguyen: ";
    cin >> n;
	int min = 9;
    for(int i=n; i>0 ; i/=10) {
    	int dv = i%10;
    	if( dv <= min){
    		min = dv;
		}
    }

    cout << "Chu so nho nhat trong so nguyen duong n la: " << min << endl;
    return 0;
}
