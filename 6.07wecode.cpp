#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    Nhapmang(a, n);
    int max_value = a[0];
    int rank_2_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_value){
            rank_2_value = max_value;
            max_value = a[i];
        }
        else if (a[i] < max_value && a[i] > rank_2_value)
        {
            rank_2_value = a[i];
        }
    }
    if (rank_2_value == 0)
    {
        cout << "0";
    }
    else
    {
        cout << rank_2_value << endl;
    }
    return 0;
}
