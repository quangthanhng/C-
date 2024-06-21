#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int So_phantu_max(int a[], int n, int max_value){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == max_value){
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    Nhapmang(a, n);
    int max_value = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max_value)
            max_value = a[i];
    }
    cout << max_value << endl;
    cout << So_phantu_max(a, n, max_value);
    return 0;
}
