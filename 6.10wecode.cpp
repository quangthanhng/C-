#include <iostream>
using namespace std;

void Nhapmang(int a[], int index)
{
    for (int i = 0; i < index; i++)
    {
        cin >> a[i];
    }
}

void sort_array(int a[], int index){
    for(int i = 0; i < index; i++){
        for(int j = i + 1; j < index; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void xuat_mang_c(int a[], int n, int b[], int m, int c[]){
    int d[1000];
    for(int i = 0; i < n; i++){
        d[i] = a[i];
    }
    for(int j = 0; j < m; j++){
        d[n + j] = b[j];
    }
    sort_array(d, m + n);
    for(int k = 0; k < m + n; k++){
        c[k] = d[k];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    Nhapmang(a, n);
    int m;
    cin >> m;
    int b[1000];
    Nhapmang(b, m);
    int c[1000];
    xuat_mang_c(a, n, b, m, c);
    for(int i = 0; i < (m + n); i++){
        cout << c[i] << " ";
    }
    return 0;
}
