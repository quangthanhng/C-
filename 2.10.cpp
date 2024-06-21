#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c <= 0)
        cout << "Nam khong hop le.";
    else if (b > 12 || b <= 0)
    {
        cout << "Thang khong hop le.";
    }
    else
    {
        if (((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) && b == 2)
        {
            if (a > 29 || a <= 0)
            {
                cout << a << "/" << b << "/" << c << " la ngay khong hop le.";
            }
            else
                cout << a << "/" << b << "/" << c << " la ngay hop le.";
        }
        else if (b == 2)
        {
            if (a > 28 || a <= 0)
            {
                cout << a << "/" << b << "/" << c << " la ngay khong hop le.";
            }
            else
                cout << a << "/" << b << "/" << c << " la ngay hop le.";
        }
        else if (b == 4 || b == 6 || b == 9 || b == 11)
        {
            if (a > 30 || a <= 0)
            {
                cout << a << "/" << b << "/" << c << " la ngay khong hop le.";
            }
            else
                cout << a << "/" << b << "/" << c << " la ngay hop le.";
        }
        else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 12)
        {
            if (a > 31 || a <= 0)
            {
                cout << a << "/" << b << "/" << c << " la ngay khong hop le.";
            }
            else
                cout << a << "/" << b << "/" << c << " la ngay hop le.";
        }
        else cout << a << "/" << b << "/" << c << " la ngay khong hop le.";
    }
}