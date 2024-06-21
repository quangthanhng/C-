#include<iostream>
#include<string>
using namespace std;

int program_1(string fullname, char x){
    int count_1 = 0;
    int i = fullname.find(x);
    while(i != std::string::npos){
        count_1++;
        fullname = fullname.substr(i+1);
        i = fullname.find(x);
    }
    return count_1;
}

int program_2(string fullname){
    int count_2 = 1;
    int i = fullname.find(' ');
    while(i != std::string::npos){
        count_2++;
        fullname = fullname.substr(i+1);
        i = fullname.find(' ');
    }
    return count_2;
}

bool program_3(string fullname, string index){
    int i = fullname.find(index);
    if( i != string::npos){
        return true;
    }
    return false;
}

string program_4(string fullname){
    int i = fullname.find(' ');
    string Family_name = fullname.substr(0,i);
    return Family_name;
}

string program_5(string fullname){
    int i = fullname.find(' ');
    while( i != string::npos){
    fullname = fullname.substr(i + 1);
    i = fullname.find(' ');
    }
    string name = fullname.substr(0);
    return name;
}

int main()
{
 std::string fullname;
 std::cout << "Nhap ho ten day du: ";
    std::getline(std::cin, fullname);
 std::cout << "Ket qua 1a: " << program_1(fullname, 'a') << "\n";
 std::cout << "Ket qua 1b: " << program_1(fullname, 'u') << "\n";
 std::cout << "Ket qua 1c: " << program_1(fullname, 'z') << "\n";
    std::cout << "Ket qua 2: " << program_2(fullname) << "\n";
    std::cout << "Ket qua 3a: " << program_3(fullname, "Nguyen") <<  "\n";
    std::cout << "Ket qua 3b: " << program_3(fullname, "Trinh") <<  "\n";
    std::cout << "Ket qua 4: " << program_4(fullname) << "\n";
    std::cout << "Ket qua 5: " << program_5(fullname) << "\n";
}