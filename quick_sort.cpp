#include <iostream>
#define max 100
using namespace std;

// Hàm phân hoạch (Partition)
int partition(int a[], int start, int end)
{
    int pi_value = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < pi_value)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(a, start, end);
        // Gọi đệ quy để chia thành 2 mảng
        quickSort(a, start, pivot - 1); // Nửa bên trái pivot
        quickSort(a, pivot + 1, end);   // Nửa bên phải pivot
    }
}

// Hàm in mảng
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm chính
int main()
{
    int arr[max] = { 4, 3, 1, 2, 5, 9, 7, 10, 8};
    int n = 9;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
