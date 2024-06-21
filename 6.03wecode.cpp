#include<iostream>
using namespace std;

void Nhapmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int main(){
    int n;
    cin >> n;
    int a[n]; // Khai báo mảng có kích thước n
    Nhapmang(a, n);
    for(int i = 1; i < n; i+=2){ // Sửa thành i < n để không vượt qua kích thước của mảng
        cout << a[i] << " "; // Thêm dấu cách để ngăn cách giữa các phần tử xuất ra
    }
    return 0;
}
