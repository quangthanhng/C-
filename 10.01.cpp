#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee
{
    int age;
    string fullname;
    float he_so;
    Employee(string s, int a, float b) : age(a), fullname(s), he_so(b)
    {
    }
    Employee()
    {
    }
};

int main()
{
    Employee person;
    float so_luong_co_ban = 3000000;
    cout << "Nhap ten: ";
    getline(cin, person.fullname);
    cout << "Nhap tuoi: ";
    cin >> person.age;
    cout << "Nhap he so luong: ";
    cin >> person.he_so;
    cout << "Tien luong cua " << person.fullname << "la: " << (unsigned long long)(so_luong_co_ban * person.he_so) << " VND" << endl;
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    Employee NV[n];
    unsigned long long tong_luong = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":\n";
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, NV[i].fullname);
        cout << "Nhap tuoi: ";
        cin >> NV[i].age;
        cout << "Nhap he so luong: ";
        cin >> NV[i].he_so;
        tong_luong += (unsigned long long)(NV[i].he_so * so_luong_co_ban);
    }
    cout << "Luong trung binh cua " << n << " nhan vien la: " << fixed << setprecision(2) << (double)(tong_luong / n) << " VND";
    return 0;
}