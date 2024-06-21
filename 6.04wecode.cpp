#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

bool Isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    Nhapmang(a, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (Isprime(a[i]))
        {
            cout << a[i] << " ";
            count++;
        }
    }
    if (count == 0)
        cout << "0"; 
    return 0;
}
