#include <iostream>
using namespace std;

#define MAX 100

void NhapMaTran(float a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void TongAB(float a[MAX][MAX], float b[MAX][MAX], int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, i, k;
    cin >> m >> n;
    float a[MAX][MAX];
    float b[MAX][MAX];
    NhapMaTran(a, m, n);
    cin >> i >> k;
    if(i != m || k != n){
        cout << "fail";
    }
    else {
        NhapMaTran(b, i, k);
        TongAB(a, b, m, n);
    }
    return 0;
}
/*
2 2
        2 2
            4 2
            3 5
        2 2
            5 6
            3 7
*/
