#include <iostream>

using namespace std;

// Hàm để hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm để điều chỉnh heap (heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;         // Giả sử gốc là lớn nhất
    int left = 2 * i + 1;    // Chỉ số con trái
    int right = 2 * i + 2;   // Chỉ số con phải

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn "lớn nhất" hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu "lớn nhất" không phải là gốc
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Đệ quy điều chỉnh lại heap
        heapify(arr, n, largest);
    }
}

// Hàm thực hiện Heap Sort
void heapSort(int arr[], int n) {
    // Xây dựng heap (tổ chức lại mảng thành Max-Heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i > 0; i--) {
        // Di chuyển phần tử gốc (lớn nhất) đến cuối mảng
        swap(arr[0], arr[i]);

        // Gọi heapify trên heap rút gọn
        heapify(arr, i, 0);
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 12, 10, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Mảng sau khi sắp xếp Heap Sort: ";
    printArray(arr, n);

    return 0;
}
