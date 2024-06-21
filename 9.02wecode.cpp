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
    int value = a[0];
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > value)
        value = a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == value)
        count++;
    }
    cout << value << endl << count;
}