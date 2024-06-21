#include<iostream>
using namespace std;
#define MAX 100

void output(int a[MAX][MAX], int& x, int& y){
    cin >> x;
    cin >> y;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> a[i][j];
        }
    }
    cout << "\n";
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << a[i][j] << " "; 
        }
        cout << "\n";
    }
}

int return_index(int a[MAX][MAX], int x, int y, int X){
    int position = -1;
    for(int i = 0; i < y; i++){
        int sum = 0;
        for(int j = 0; j < x; j++){
            sum += a[j][i];
        }
        if(sum == X){
            position = i;
        }
    }
    return position;
}

int main(){
    int a[MAX][MAX];
    int x, y;
    output(a, x, y);
    cout << "\n";
    // cau a
    int X;
    cin >> X;
    cout << "return index is: " << return_index(a, x, y, X);
    // cau b
}
