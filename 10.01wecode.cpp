#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

class PhanSo
{
public:
    int tuso;
    int mauso;
};

// Hàm tính ước số chung lớn nhất
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm nhập mảng phân số
void Nhap(PhanSo a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].tuso >> a[i].mauso;
    }
}

// Hàm xuất mảng phân số đã tối giản
void Xuat(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].mauso == 0)
        {
            cout << "Khong thoa yeu cau bai toan" << endl;
        }
        else
        {
            // Tối giản phân số
            int g = gcd(a[i].tuso, a[i].mauso);
            a[i].tuso /= g;
            a[i].mauso /= g;

            // Đảm bảo mẫu số không âm
            if (a[i].mauso < 0)
            {
                a[i].tuso = -a[i].tuso;
                a[i].mauso = -a[i].mauso;
            }

            // Xuất phân số
            if (a[i].mauso == 1)
            {
                cout << a[i].tuso << endl;
            }
            else if (a[i].tuso == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << a[i].tuso << "/" << a[i].mauso << endl;
            }
        }
    }
}

int main()
{
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}
