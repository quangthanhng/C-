#include <iostream>
using namespace std;

int Input()
{
    int n;
    cin >> n;
    return n;
}

int sum_even_divisor(int &n)
{
    int sum = 0;
    for (int i = 2; i <= n; i += 2)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (sum > 0)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n;
    n = Input();
    cout << sum_even_divisor(n);
}
