#include<iostream>

using namespace std;
int input(){
    int n;
    cin >> n;
    return n;
}

int input(int& m){
    cin >> m;
    return m;
}

int TongUocChung(int a, int b){
    int smaller_value;
    if(a < b){
        smaller_value = a;
    }else if( a == b ){
        smaller_value = a;
    }else {
        smaller_value = b;
    }
    int sum = 0;
    for(int i = 1; i <= smaller_value; i++){
        if(a % i == 0 && b % i == 0){
            sum += i;
        }
    }
    return sum;
}


int main(){
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}

