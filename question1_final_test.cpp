#include<iostream>
#include<iomanip>
#define MAX 100
using namespace std;

void input(int A[MAX], int& n){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
}

void output(int A[MAX], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void remove_duplicate(int A[MAX], int& n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(A[j] == A[i]){
                for(int k = j; k < n; k++){
                    A[k] = A[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void display_integers(int A[MAX], int n, int& X){
    std::cin >> X;
    for(int i = 1; i <= X; i++){
        bool check = true;
        for(int j = 0; j < n; j++){
            if(i == A[j]){
                check = false;
                break;
            }
        }
        if(check == true && i != X){
            cout << i << ", ";
        }else if(check == true && i == X){
            cout << i << ".";
        }
    }
}

int main(){
    int A[MAX];
    int n;
    input(A, n);
    output(A, n);
    // cau a
    remove_duplicate(A, n);
    // cau b
    int X;
    display_integers(A, n, X);
    // cau c
}