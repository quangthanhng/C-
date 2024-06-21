#include <iostream>
using namespace std;

// Định nghĩa struct cho điểm
struct Diem {
    int x;
    int y;
};

// Định nghĩa struct cho hình vuông
struct HinhVuong {
    Diem diemTrenTrai; // Điểm trên cùng bên trái
    int doDaiCanh; // Độ dài cạnh của hình vuông
};

// Hàm nhập vào một mảng gồm n hình vuông
void nhapHinhVuong(HinhVuong hinhVuong[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhập tọa độ góc trên bên trái (x y) của hình vuông " << i + 1 << ": ";
        cin >> hinhVuong[i].diemTrenTrai.x >> hinhVuong[i].diemTrenTrai.y;
        cout << "Nhập độ dài cạnh của hình vuông " << i + 1 << ": ";
        cin >> hinhVuong[i].doDaiCanh;
    }
}

// Hàm kiểm tra nếu một điểm nằm trong một hình vuông
bool kiemTraDiemTrongHinhVuong(const Diem& diem, const HinhVuong& hinhVuong) {
    return (diem.x >= hinhVuong.diemTrenTrai.x && 
            diem.x <= hinhVuong.diemTrenTrai.x + hinhVuong.doDaiCanh &&
            diem.y >= hinhVuong.diemTrenTrai.y && 
            diem.y <= hinhVuong.diemTrenTrai.y + hinhVuong.doDaiCanh);
}

int main() {
    int n;
    cout << "Nhập số lượng hình vuông: ";
    cin >> n;

    HinhVuong hinhVuong[n];
    nhapHinhVuong(hinhVuong, n);

    // In ra thông tin các hình vuông vừa nhập (tùy chọn)
    for (int i = 0; i < n; i++) {
        cout << "Hình vuông " << i + 1 << ": "
             << "Góc trên bên trái (" << hinhVuong[i].diemTrenTrai.x << ", " << hinhVuong[i].diemTrenTrai.y << "), "
             << "Độ dài cạnh " << hinhVuong[i].doDaiCanh << endl;
    }

    // Kiểm tra nếu một điểm nằm trong một hình vuông
    Diem diem;
    cout << "Nhập tọa độ điểm cần kiểm tra (x y): ";
    cin >> diem.x >> diem.y;

    for (int i = 0; i < n; i++) {
        if (kiemTraDiemTrongHinhVuong(diem, hinhVuong[i])) {
            cout << "Điểm (" << diem.x << ", " << diem.y << ") nằm trong hình vuông " << i + 1 << endl;
        } else {
            cout << "Điểm (" << diem.x << ", " << diem.y << ") không nằm trong hình vuông " << i + 1 << endl;
        }
    }

    return 0;
}
