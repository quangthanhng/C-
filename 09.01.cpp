#include<iostream>
using namespace std;

int program_1(char x){
    if((int)x >= 65 && (int)x <= 90){
        return 1;
    }else if( (int)x >= 97 && (int)x <= 122){
        return -1;
    }else return 0;
}

int program_2(char x){
    if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z'){
        return 1;
    }else if( x >= '1' && x <= '9'){
        return -1;
    }else return 0;
}

char program_3(char x){
    if( x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '1' && x <= '9'){
        if( x == '9' || x == 'z' || x == 'Z'){
            return x;
        }
        return (x+1);
    } else return x;
}

int main()
{
  char x;
 std::cout << "Nhap ki tu don: ";cin >> x;
 std::cout << "Ket qua 1: " << program_1(x) << "\n";
 std::cout << "Ket qua 2: " << program_2(x) << "\n";
 std::cout << "Ket qua 3: " << program_3(x) << "\n";
}