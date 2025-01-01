#include <iostream>
#include <string>
using namespace std;

int BinarySearch(string a[], string value, int d, int c){
    while (d <= c){
        int m = (d + c) / 2;
        if (a[m] == value) {
            return m;
        }
        else if (a[m] > value) {
            c = m - 1;          }
        else {
            d = m + 1;
        }
    }
    return d;
}

void solution(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string value = arr[i];
        int j = BinarySearch(arr, value, 0, i - 1);
        
        for (int k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        
        arr[j] = value;
    }
}

int main(){
    int n;
    cin >> n;
    string arr[10000];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    solution(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}