#include<iostream>
using namespace std;

# define MAXR 100
# define MAXC 100

void NhapMaTran(float a[MAXR][MAXC], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}

bool isMaTranDoiXung(float a[MAXR][MAXC], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[0][j] != a[j][0]){
                return false;
                break;
            }
        }
    }
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;
    float a[MAXR][MAXC];
    NhapMaTran(a, m, n);
    cout << (isMaTranDoiXung(a, m, n) ? "Yes" : "No");
}