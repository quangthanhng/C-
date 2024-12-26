#include<iostream>
using namespace std;
#define max 100

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int a[], int value, int j){
    for( ; j > 0; j--){
        if(value > a[j - 1]){
            return;
        }
        a[j] = a[j - 1];
    }
    a[j] = value; 
}

void solution(int a[], int n){
    for(int i = 1; i < n; i++){
        insert(a, a[i], i);
    }
    print(a, n);
}

int main(){
    int a[max];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solution(a, n);
}