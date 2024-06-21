#include<iostream>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    float A[m][n];

    // Nhập các phần tử của mảng
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    // Xuất các phần tử của mảng
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl; // Để in ra mỗi hàng trên một dòng mới
    }

    return 0;
}
