#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Nhap vao mot so nguyen: ";
    cin >> n;
	int max = 0;
    for(int i=n; i>0 ; i/=10) {
    	int dv = i%10;
    	if( dv > max){
    		max = dv;
		}
    }

    cout << "Chu so lon nhat trong so nguyen duong n la: " << max << endl;
    return 0;
}
