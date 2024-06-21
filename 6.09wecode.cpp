#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void delete_array(int a[], int &n)
{
    int p, k;
    cin >> p >> k;
    if (p >= 0 && p <= (n - 1) && k <= (n - p))
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = p; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    Nhapmang(a, n);
    delete_array(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
