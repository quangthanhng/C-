#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien A[MAXN], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].MASV;
        cin.ignore();              // Để bỏ qua ký tự xuống dòng sau MASV
        cin.getline(A[i].HoTen, 100); // Đọc toàn bộ dòng cho họ tên
        cin >> A[i].NgaySinh;
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan;
        cin >> A[i].DiemLy;
        cin >> A[i].DiemHoa;
    }
    cout << endl;
}

void SapXepGiamTheoMASV(SinhVien A[MAXN], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(A[j].MASV, A[i].MASV) > 0)
            {
                SinhVien temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void Xuat(SinhVien A[MAXN], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i].MASV << "\t";
        cout << A[i].HoTen << "\t";
        cout << A[i].NgaySinh << "\t";
        cout << A[i].GioiTinh << "\t";
        
        if ((int)(A[i].DiemToan * 10) % 10 == 0)
        {
            cout << fixed << setprecision(0) << A[i].DiemToan << "\t";
        }
        else if ((int)(A[i].DiemToan * 100) % 10 == 0)
        {
            cout << fixed << setprecision(1) << A[i].DiemToan << "\t";
        }
        else
        {
            cout << fixed << setprecision(2) << A[i].DiemToan << "\t"; // Hiển thị đúng điểm trung bình
        }
        if ((int)(A[i].DiemLy * 10) % 10 == 0)
        {
            cout << fixed << setprecision(0) << A[i].DiemLy << "\t";
        }
        else if ((int)(A[i].DiemLy * 100) % 10 == 0)
        {
            cout << fixed << setprecision(1) << A[i].DiemLy << "\t";
        }
        else
        {
            cout << fixed << setprecision(2) << A[i].DiemLy << "\t"; // Hiển thị đúng điểm trung bình
        }
        if ((int)(A[i].DiemHoa * 10) % 10 == 0)
        {
            cout << fixed << setprecision(0) << A[i].DiemHoa << "\t";
        }
        else if ((int)(A[i].DiemHoa * 100) % 10 == 0)
        {
            cout << fixed << setprecision(1) << A[i].DiemHoa << "\t";
        }
        else
        {
            cout << fixed << setprecision(2) << A[i].DiemHoa << "\t"; // Hiển thị đúng điểm trung bình
        }
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3;
        if ((int)(A[i].DTB * 10) % 10 == 0)
        {
            cout << fixed << setprecision(0) << A[i].DTB << endl;
        }
        else if ((int)(A[i].DTB * 100) % 10 == 0)
        {
            cout << fixed << setprecision(1) << A[i].DTB << endl;
        }
        else
        {
            cout << fixed << setprecision(2) << A[i].DTB << endl; // Hiển thị đúng điểm trung bình
        }
    }
}

int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}

/*
3
07520045
Nguyen Thi Lan
27/05/1989
F
10
9
8
07520504
Luong Thanh
31/07/1989
M
10
9.5
10
07520111
Nguyen Anh Hong
07/12/1991
F
7
9
8
07520504	Luong Thanh	31/07/1989	M	10	9.5	10	9.83
07520111	Nguyen Anh Hong	07/12/1991	F	7	9	8	8
07520045	Nguyen Thi Lan	27/05/1989	F	10	9	8	9
*/
