#include <iostream>
using namespace std;

int input(int& a){
    cin >> a;
    return a;
}

int TongChuSo(int a){
    int sum = 0;
    for(int i = a; i > 0; i/= 10){
        sum += (i % 10);
    }
    return sum;
}

int main()
{
    int a;
    input(a);
    std::cout << TongChuSo(a);
    return 0;
}
