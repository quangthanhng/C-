#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c;
    cout << "Nhap do dai canh a: ";
    cin >> a;
    cout << "Nhap do dai canh b: ";
    cin >> b;
    cout << "Nhap do dai canh c: ";
    cin >> c;
    if (((a + b) < c || (a + c) < b || (b + c) < a))
    {
        cout << "Khong ton tai tam giac";
    }
    else if (a == b && b == c)
    {
        cout << "Tam giac deu";
    }
    else if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) <= 0.01 && a == b) || ((pow(b, 2) + pow(c, 2) - pow(a, 2)) <= 0.01 && b == c) || ((pow(a, 2) + pow(c, 2) - pow(b, 2)) <= 0.01 && a == c))
    {
        cout << "Day la tam giac vuong can";
    }
    else if (a == b || b == c || a == c)
    {
        cout << "Tam giac can";
    }
    else if ((pow(a, 2) + pow(b, 2) - pow(c, 2)) <= 0.01 || (pow(b, 2) + pow(c, 2) - pow(a, 2)) <= 0.01 || (pow(a, 2) + pow(c, 2) - pow(b, 2)) <= 0.01)
    {
        cout << "Day la tam giac vuong";
    }
    else
    {
        cout << "Tam giac thuong";
    }
    return 0;
}