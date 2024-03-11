#include <iostream>
#include <math.h>
using namespace std;

int tonggiatri(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    double sum = 0;
    int n;
    cout << "Nhap vao gia tri n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += 1 / (double)tonggiatri(i);
    }
    cout << sum;
    return 0;
}