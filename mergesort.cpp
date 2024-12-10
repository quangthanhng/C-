#include<iostream>

using namespace std;
#define max 100
int n;
int a[max];

void print(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void combine(int start, int mid, int end){
    int n1 = mid - start + 1; // Kích thước mảng con bên trái
    int n2 = end - mid;       // Kích thước mảng con bên phải

    // Tạo mảng tạm
    int L[n1], R[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = a[start + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    // Gộp hai mảng con trở lại mảng chính
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int start, int end){
    if(start == end){
        return;
    }

    int mid = (start + end)/2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    combine(start, mid, end);
}

void solution(){
    mergesort(0, n - 1);
    print();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solution();
}