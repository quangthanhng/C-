#include<iostream>
using namespace std;
# define MAX 100

int main(){
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i += 2){
        cout << a[i] << " ";
    }
}