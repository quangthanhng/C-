#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Insert_element(int a[], int& n){
    int k, x;
    cin >> x >> k;
    if(k >= 0 && k <= 6){
        for(int i = n; i > k; i--){
            a[i] = a[i - 1];
        }
        a[k] = x;
        n++;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    Nhapmang(a, n);
    int count = 0;
    Insert_element(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
