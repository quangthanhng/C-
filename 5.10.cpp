#include<iostream>
using namespace std;
int main(){
    for(int i = 0; i<= 9; i++){
        for(int j = 0 ; j <= 9; j++){
            if (i % 2 == 0){
                cout << j << " ";
            }else {
                cout << 9 - j << " ";
            }
        }
        cout << endl ;
    }
    return 0;
}