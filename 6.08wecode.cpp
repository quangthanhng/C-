#include <iostream>
using namespace std;

void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void delete_array(int a[], int& n){
    int x;
    cin >> x;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            for(int j = i; j < n; j++){
                a[j] = a[j + 1];
            }
            n--;
            i--;
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
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
