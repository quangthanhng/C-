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



int main() {
    float a[MAXR][MAXC], m, n;
    cin >> m >> n;
    NhapMaTran(a, m, n);
    float count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                count += a[i][j];
            }
        }
    }
    cout << count;
    return 0;
}
