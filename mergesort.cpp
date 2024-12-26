#include <iostream>
using namespace std;
#define max 100

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void combine(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Kích thước mảng trái
    int n2 = right - mid;     // Kích thước mảng phải

    // Tạo hai mảng tạm
    int L[n1], R[n2];

    // Sao chép dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng tạm lại vào mảng chính
    int i = 0; // Chỉ số của mảng trái
    int j = 0; // Chỉ số của mảng phải
    int k = left; // Chỉ số của mảng chính

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng trái (nếu còn)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng phải (nếu còn)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tìm chỉ số giữa mảng
        int mid = left + (right - left) / 2;

        // Gọi đệ quy cho nửa trái
        mergeSort(arr, left, mid);

        // Gọi đệ quy cho nửa phải
        mergeSort(arr, mid + 1, right);

        // Hợp nhất hai nửa
        combine(arr, left, mid, right);
    }
}
void solution(int a[], int n)
{
    mergeSort(a, 0, n - 1);
    print(a, n);
}

int main()
{
    int a[max];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solution(a, n);
}