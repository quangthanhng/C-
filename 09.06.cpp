#include<iostream>
#include<string>
using namespace std;

string program_1(string s){
    string longest_name;
    int i = s.find(';');
    while(i != string::npos){
        longest_name = s.substr(0,i);
        break;
    }
    int j = s.find(';');
    while( j != string::npos){
        string compared = s.substr(0,j);
        if( compared.length() > longest_name.length()){
            longest_name = compared;
        }
        s = s.substr(j+1);
        j = s.find(';');
    }
    return longest_name;
}

float program_2(string s){
    string chuoi_s = s;
    float count = 1;
    int i = chuoi_s.find(';');
    while( i != string::npos){
        count++;
        chuoi_s = chuoi_s.substr(i + 1);
        i = chuoi_s.find(';');
    }
    float ketqua = (s.length() - (count - 1))/(count);
    return ketqua; 
}

string program_3(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ' || (isalpha(s[i]) == false)){
            s.replace(i, 1, "");
        }
    }
    return s;
}

int main(){
    std::string data;
    std::cout << "Nhap danh sach: ";
    std::getline(std::cin, data);
    cout << "Ket qua chuong trinh 1: " << program_1(data) << endl;
    cout << "Ket qua chuong trinh 2: " << program_2(data) << endl;
    cout << "Ket qua chuong trinh 3: " << program_3(data) << endl;
}