#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Nhap vao mot so nguyen: ";
    cin >> n;
	int dem = 0;
    for(int i=n; i>0 ; i/=10) {
    	if((i%10) % 2 == 0){
    		dem += i%10;
		}
    }

    cout << "Tich cac chu so le trong so nguyen duong n la: " << dem << endl;
    return 0;
}
