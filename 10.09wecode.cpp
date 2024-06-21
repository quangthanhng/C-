#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 100
using namespace std;
struct DATHUC {
    double a[MAX];
    int somu[MAX];
    int length;
};
DATHUC* Nhap() {
    DATHUC* B = new DATHUC;
    cin >> B->length;
    for (int i = 0; i < B->length; i++) {
        cin >> B->a[i] >> B->somu[i];
    }
    return B;
}
/*
Biến trong đa thức ký hiệu là x.
Số mũ ký hiệu ^.
Phép nhân không ghi ký hiệu.
Các ký tự biểu diễn đa thức ghi liền nhau (không khoảng trắng).
Đơn thức đầu tiên nếu hệ số là số dương thì không được xuất dấu + trước hệ số.
Đơn thức có hệ số bằng 0 thì không xuất đơn thức đó.
Đơn thức có hệ số bằng 1 hoặc -1 thì không xuất số 1.
Đơn thức có số mũ bằng 0 thì chỉ xuất hệ số của đơn thức.
Đơn thức có số mũ bằng 1 thì không xuất số mũ.
*/
void Xuat(DATHUC B) {
    bool first = true;
    for (int i = 0; i < B.length; i++) {
        double he_so = B.a[i];
        int so_mu = B.somu[i];

        if (he_so == 0) continue;

        if (!first) {
            if (he_so > 0) cout << "+";
        }
        first = false;

        if (so_mu == 0) {
            cout << he_so;
        } else if (so_mu == 1) {
            if (he_so == 1) cout << "x";
            else if (he_so == -1) cout << "-x";
            else cout << he_so << "x";
        } else {
            if (he_so == 1) cout << "x^" << so_mu;
            else if (he_so == -1) cout << "-x^" << so_mu;
            else cout << he_so << "x^" << so_mu;
        }
    }
    if (first) cout << "0";  // In 0 nếu tất cả các hệ số đều là 0
}

double TinhDaThuc(DATHUC B, double x) {
    double result = 0.0;
    for (int i = 0; i < B.length; i++) {
        result += B.a[i] * pow(x, B.somu[i]);
    }
    return result;
}

int main() {
    DATHUC* B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
