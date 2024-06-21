#include <iostream>
using namespace std;

// Hàm đệ quy để đếm số lần xuất hiện của phần tử x trong mảng arr có n phần tử
int countOccurrences(int arr[], int n, int x) {
    // Trường hợp cơ bản: Nếu mảng không còn phần tử nào để kiểm tra, trả về 0
    if (n == 0)
        return 0;
    
    // Trường hợp đệ quy: Kiểm tra phần tử cuối cùng của mảng
    if (arr[n-1] == x)
        return 1 + countOccurrences(arr, n-1, x); // Nếu phần tử cuối cùng bằng x, cộng 1 vào kết quả
    else
        return countOccurrences(arr, n-1, x); // Nếu phần tử cuối cùng không bằng x, tiếp tục kiểm tra các phần tử còn lại
}

int main() {
    int arr[] = {1, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    cout << "Số lần xuất hiện của phần tử " << x << " trong mảng là: " << countOccurrences(arr, n, x) << endl;
    return 0;
}
