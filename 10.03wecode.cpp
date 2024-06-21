#include<iostream>
using namespace std;

struct PhanSo {
    int tuso;
    int mauso;
};

PhanSo Nhap(PhanSo& a){
    cin >> a.tuso >> a.mauso;
    return a;
}

PhanSo Nhap(){
    PhanSo b;
    cin >> b.tuso >> b.mauso;
    return b;
}

void Xuat(PhanSo c){
    if(c.tuso % c.mauso == 0){
        cout << c.tuso / c.mauso;
    }else {
        cout << c.tuso << "/" << c.mauso;
    }
}

/*
3/9 + 9/4
*/

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

PhanSo Cong(PhanSo a, PhanSo b){
    PhanSo c;
    c.tuso = a.tuso * b.mauso + b.tuso * a.mauso;
    c.mauso = a.mauso * b.mauso;
    int value = gcd(c.tuso, c.mauso);
    c.tuso /= value;
    c.mauso /= value;
    return c;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Cong(a, b));
    return 0;
}
