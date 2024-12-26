#include<iostream>
using namespace std;
#define max 100

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
 
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void solution(int a[], int n){
    bool check = true;
    for( ;check == true; ){
        check = false;
        for(int i = 0; i <= n - 2; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                check = true;
            }
        }
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