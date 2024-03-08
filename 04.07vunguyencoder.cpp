#include <iostream>
using namespace std;

int main()
{
    float x, y, z;
    cout << " Nhap vao so x: ";
    cin >> x;
    cout << " Nhap vao so y: ";
    cin >> y;
    cout << " Nhap vao so z: ";
    cin >> z;
    if (x > y && x > z)
    {
        cout << " so lon nhat la " << x << endl;
    }
    else if (y > x && y > z)
    {
        cout << " so lon nhat la " << y << endl;
    }
    else if (z > x && z > y)
    {
        cout << " so lon nhat la " << z << endl;
    }
    if (x * (y * z) > 0)
    {
        cout << " Ca 3 so cung dau" << endl;
    }
    else
    {
        cout << "3 so khac dau" << endl;
    }
    if ((x * y) < 0)
    {
        cout << " Cap so khac dau la: " << x << ";" << y << endl;
    }
    if ((y * z) < 0)
    {
        cout << " Cap so khac dau la: " << y << ";" << z << endl;
    }
    if ((x * z) < 0)
    {
        cout << " Cap so khac dau la: " << x << ";" << z << endl;
    }
    return 0;
}