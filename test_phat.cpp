#include<iostream>

using namespace std;

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b; 
    b = temp;
}

void selectionsort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    print(a, n);
    selectionsort(a, n);
    print(a, n);
}