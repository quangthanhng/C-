#include<iostream>
using namespace std;
# define max 100

void selection_sort(int a[], int n){
    for(int i = 0; i < n; i++){
        int minindex = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minindex]){
                minindex = j;
            }
        }
        std::swap(a[i], a[minindex]);
    }
}

int main(){
    int a[max];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selection_sort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}