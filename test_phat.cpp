#include <iostream>
#include<string>
using namespace std;

string fix(string fullname){
    fullname[0] = toupper(fullname[0]);
    for (int i = 1; i < fullname.length(); i++)
    {
        fullname[i] = tolower(fullname[i]);
        if (fullname[i - 1] == ' ')
        { // nguyen anh vu
            fullname[i] = toupper(fullname[i]);
        }
    }
    return fullname;
}

int main() {
    string name;
    cout << "Nhập tên: ";
    getline(cin, name); // Đọc cả dòng nhập vào từ người dùng

    string newname = fix(name);
    cout << "Tên đã sửa lại là: " << newname << endl;

    return 0;
}