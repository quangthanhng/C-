#include<iostream>
using namespace std;
# define MAX 100

void NhapMang(int a[MAX], int x){
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }
}

void sortArray(int a[MAX], int x){
    for(int i = 0; i < x; i++){
        for(int j = i + 1; j < x; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int m;
    cin >> m;
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int length_c = 0;
    NhapMang(a, m);
    int n;
    cin >> n;
    NhapMang(b, n);
    for(int i = 0; i < m; i++){
        c[i] = a[i];
        length_c++;
    }
    for(int j = 0; j < n; j++){
        c[m + j] = b[j];
        length_c++;
    }
    sortArray(c, length_c);
    for(int i = 0; i < length_c; i++){
        cout << c[i] << " ";
    }
}