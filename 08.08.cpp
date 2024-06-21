#include<iostream>
using namespace std;

int program_1(int length){
    return length * sizeof(int);
}

void program_2(int a[],int length){
    for(int i = 0; i < length; i++){
        cout << &a[i] << "\t" << a[i] << "\n\t";
    }
}

int main()
{
    const int length = 5; 
    int a[length] = {1, 6, 3, 7, 2 };
    cout << "Ket qua 1: " << program_1(length) << " bytes\n";
    cout << "Ket qua 2:\n" << "\tDiachi \t\tGiatri\n \t";
    program_2(a,length);
}