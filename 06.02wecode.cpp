#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n,int y);



bool Isprime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void NhapmangSNT(int a[], int& n){
    cin >> n;
    int temp = 2;
    for(int i = 0; i < n;){
        if(Isprime(temp)){ // Thay đổi điều kiện từ Isprime(n) thành Isprime(temp)
            a[i] = temp;
            i++;
        }
        temp++;
    }
}

int SoPhanTuChuaY(int a[], int n, int y){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = a[i]; j > 0; j /= 10){ // Sửa điều kiện lặp từ j >= 0 thành j > 0
            if(j % 10 == y){ // Thay đổi từ j == y thành j % 10 == y
                count++;
                break;
            }
        }
    }
    return count;
}


int main()
{
	int a[MAX], n, y;
	cin >>y;
	NhapmangSNT(a,n);
	cout << SoPhanTuChuaY(a, n, y) << endl;;
	return 0;
}