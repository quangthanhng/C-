#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double n;
    cout << "Nhap vao so n: ";
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1 / (double)(i * (i + 1));
    }
    cout << sum;
    return 0;
}