#include<iostream>
#include<string>

using namespace std;

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;  // Giả sử phần tử nhỏ nhất là phần tử ở vị trí i
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;  // Tìm vị trí phần tử nhỏ nhất
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên chưa sắp xếp
        if (minIdx != i) {
            swap(a[i], a[minIdx]);
        }
    }
}


int main() {
    int n;
    int a[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selection_sort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
