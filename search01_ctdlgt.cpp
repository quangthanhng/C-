#include<iostream>
using namespace std;
#define MAX 100

int binary_search(int a[], int b[], int m, int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        int start = 0;
        int end = m - 1;
        while(start <= end){
        int mid = (start + end)/2;
        if(a[mid] == b[i]){
            count++;
        }

        if(b[i] > a[mid]){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        cout << count << endl;
    }
    return 0;
    }
}

int main(){
    int m, n;
    int a[MAX];
    int b[MAX];
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int j = 0; j < n; j++){
        cin >> b[j];
    }
    cout << binary_search(a, b, m, n);
}