#include <iostream>

using namespace std;

int doubleFactorial(int n)
{
    long long result = 1;

    for (int i = ((n % 2 == 0) ? 2 : 1); i <= n; i += 2)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << doubleFactorial(n);
    return 0;
}
