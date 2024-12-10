#include <iostream>
# define max 100
using namespace std;

// Hàm phân hoạch (Partition)
int partition(int arr[], int start, int end) {
    int pivot = arr[end]; // Chọn phần tử chốt (pivot) là phần tử cuối
    int i = start - 1;    // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            // Hoán đổi arr[i] và arr[j]
            swap(arr[i], arr[j]);
        }
    }
    // Đưa pivot vào đúng vị trí
    swap(arr[i + 1], arr[end]);
    return i + 1; // Trả về chỉ số của pivot
}

// Hàm Quick Sort
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end); // Chỉ số phân hoạch

        // Đệ quy sắp xếp hai nửa
        quickSort(arr, start, pi - 1); // Nửa bên trái
        quickSort(arr, pi + 1, end);  // Nửa bên phải
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm chính
int main() {
    int arr[max];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
