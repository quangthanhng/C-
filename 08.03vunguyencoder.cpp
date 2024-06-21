# include <iostream>

using namespace std;

int main(){
    const int length = 1000;
    int a [length];

    cout << " Nhap so luong phan tu: ";
    int n; cin >> n;

    cout << " Nhap lien tiep " << n << " gia tri: ";
    for( int i = 0; i < n; i++) cin >> a[i];
    cout << " Ket qua 1: " << a[0] + a[n-1] << endl;
    if( n % 2 == 0){
        cout << " Ket qua 2: " << a[n/2 - 1] << " " << a[n/2] << endl;
    }else if( n % 2 != 0){
        cout << " Ket qua 2: " << a[n/2] << endl;
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            sum1 += a[i];
        }else if( a[i] % 2 != 0){
            sum2 += a[i];
        }
    }
    cout << " Ket qua 3: " << sum1 * sum2;
    return 0;
}