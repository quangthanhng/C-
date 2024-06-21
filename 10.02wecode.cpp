#include <iostream>
using namespace std;

struct PhanSo {
    int tuso;
    int mauso;
};

// Hàm nhập một phân số và kiểm tra điều kiện mẫu số khác 0
PhanSo Nhap(PhanSo& a) {
    cin >> a.tuso >> a.mauso;
    while (a.mauso == 0) {
        cout << "Mau so phai khac 0. Nhap lai: ";
        cin >> a.tuso >> a.mauso;
    }
    return a;
}

PhanSo Nhap() {
    PhanSo b;
    cin >> b.tuso >> b.mauso;
    while (b.mauso == 0) {
        cout << "Mau so phai khac 0. Nhap lai: ";
        cin >> b.tuso >> b.mauso;
    }
    return b;
}
int SoSanh(PhanSo a, PhanSo b){
    float k = (float)(a.tuso) / a.mauso;
    float j = (float)(b.tuso) / b.mauso;
    float kq = k - j;
    if(kq == 0){
        return kq;
    }else if(kq > 0){
        kq += 1;
        return kq;
    }else {
        kq -= 1;
        return kq;
    }
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}
