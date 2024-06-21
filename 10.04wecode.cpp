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

// Hàm tính ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return abs(a); // GCD luôn là số dương
}

// Hàm chia hai phân số và rút gọn kết quả
PhanSo Chia(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tuso = a.tuso * b.mauso;
    c.mauso = a.mauso * b.tuso;
    if (c.mauso == 0) {
        cout << "Loi: Mau so cua ket qua bang 0" << endl;
        exit(1); // Thoát chương trình nếu mẫu số bằng 0
    }
    int value = gcd(c.tuso, c.mauso);
    c.tuso /= value;
    c.mauso /= value;
    // Đảm bảo mẫu số dương
    if (c.mauso < 0) {
        c.tuso = -c.tuso;
        c.mauso = -c.mauso;
    }
    return c;
}

// Hàm xuất một phân số
void Xuat(PhanSo c) {
    if (c.mauso == 1) {
        cout << c.tuso << endl;
    } else if (c.tuso == 0) {
        cout << "0" << endl;
    } else {
        cout << c.tuso << "/" << c.mauso << endl;
    }
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Chia(a, b));
    return 0;
}
