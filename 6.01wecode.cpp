
#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}
bool isBenford( int a[], int n ){
    int count_1 = 0;
    int count_4 = 0;
    for(int i = 0; i < 10; i++){
        int temp;
        for( int j = a[i]; j > 0; j/=10){
            temp = j;
        }
        if( temp == 1 ){
            count_1++;
        }else if( temp == 4 ){
            count_4++;
        }
    }
    if( count_1 == 3 && count_4 == 1){
        return true;
    }
    else return false;
}

int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}
