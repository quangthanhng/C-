#include <iostream>

using namespace std;
int main()
{
    float a, b, c;
    cout << "Nhap vao so a: ";
    cin >> a;
    cout << "Nhap vao so b: ";
    cin >> b;
    c = a * b;
    if (a == 0)
    {
        cout << " a bang 0 "<< endl;
    }
    else
        cout << " a khac 0"<< endl;
    if (b == 0)
    {
        cout << " b bang 0"<< endl;
    }
    else
        cout << " b khac 0"<< endl;
    if (c > 0)
    {
        cout << " Hai so cung dau ";
    }
    else if (c < 0)
    {
        cout << " Hai so khac dau";
    }
    return 0;
}