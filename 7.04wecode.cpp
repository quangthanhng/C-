#include<iostream>
using namespace std;

#define MAXR 100
#define MAXC 100

void NhapMaTran(float a[MAXR][MAXC], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void MaTranChuyenVi(float a[MAXR][MAXC], int m, int n){
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    float a[MAXR][MAXC], m, n;
    cin >> m >> n;
    NhapMaTran(a, m, n);
    MaTranChuyenVi(a, m, n);
    return 0;
}
