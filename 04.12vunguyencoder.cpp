#include<iostream>

using namespace std;

int main(){
    double toan, ly, hoa, van, anh, su, dia, dtb;
    cout << " Nhap diem toan ";
    cin >> toan;
    cout << " Nhap diem ly ";
    cin >> ly;
    cout << " Nhap diem hoa ";
    cin >> hoa;
    cout << " Nhap diem van ";
    cin >> van;
    cout << " Nhap diem anh ";
    cin >> anh;
    cout << " Nhap diem su ";
    cin >> su;
    cout << " Nhap diem dia ";
    dtb = (toan + ly + hoa + van + anh + anh + su + dia)/7;
    cin >> dia;
    if ( (toan > 10 || toan < 0) || (ly > 10 || ly < 0) || (hoa > 10 || hoa < 0) || (van > 10 || van < 0) || (anh > 10 || anh < 0) || (su > 10 || su < 0) || (dia > 10 || dia < 0)){
        cout << "Diem khong hop le"<< endl;
    }else {
        cout << "Diem trung binh cua hoc sinh la: " << dtb << endl;
    }
    
}