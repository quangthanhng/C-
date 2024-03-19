#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a0 = -1, a1 = 3, ahh, n;
    cout << " Hay nhap vao so n: ";
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ahh = (5 * a1) + (6 * a0);
        a0 = a1;
        a1 = ahh;
    }
    cout << a1;
    return 0;
}