#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    double dt = sqrt(p * (p - a) * (p - b) * (p - c));
    if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
    {
        cout << "Khong phai tam giac";
    }
    else if (a == b && a == c)
    {
        cout << "Tam giac deu, dien tich = " << fixed << setprecision(2) << dt;
    }
    else if (a == b || a == c || b == c)
    {
        cout << "Tam giac can, dien tich = " << fixed << setprecision(2) << dt;
    }
    else if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)) || (pow(c, 2) + pow(b, 2) == pow(a, 2)))
    {
        cout << "Tam giac vuong, dien tich = " << fixed << setprecision(2) << dt;
    }
    else
        cout << "Tam giac thuong, dien tich = " << fixed << setprecision(2) << dt;
    return 0;
}