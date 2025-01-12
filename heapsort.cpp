#include <iostream>

using namespace std;

// Hàm để hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //Nếu node con trái lớn hơn node cha hiện tại 
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    //Nếu node con phải lớn hơn node cha hiện tại 
    if(right < n && a[right] > a[largest]){
        largest = right;
    }
    // Nếu node lớn nhất không phải là node hiện tại
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

// Hàm để điều chỉnh heap (heapify)
void heapSort(int a[], int n){
    // Xây dựng một heap max 
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    // Trích xuất từ phần tử lớn nhất max heap và sắp xếp
    // for(int i = n - 1; i > 0; i--){
    //     //Đưa phần tử lớn nhất về cuối mảng
    //     swap(a[0], a[i]);
    //     //Gọi heapify để tạo heap max cho phần còn lại
    //     heapify(a, i, 0);
    // }

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
