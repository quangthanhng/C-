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

bool isMaTranDuongCheo(float a[MAXR][MAXC], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i != j && a[i][j] != 0){
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
    cout << (isMaTranDuongCheo(a, m, n) ? "Yes" : "No");
}