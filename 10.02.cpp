#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Point
{
public:
    float x, y, z;
    float magnitude(float x, float y, float z)
    {
        return x * x + y * y + z * z;
    }
};
float program_1(Point A)
{
    float kq = sqrt(pow(A.x, 2) + pow(A.y, 2) + pow(A.z, 2));
    return kq;
}
float program_2(Point A, Point B)
{
    float kq = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2) + pow((B.z - A.z), 2));
    return kq;
}

float program_3(Point A, Point B)
{
    float a = A.x * B.x + A.y * B.y + A.z * B.z;
    float b = sqrt(pow(A.x, 2) + pow(A.y, 2) + pow(A.z, 2));
    float c = sqrt(pow(B.x, 2) + pow(B.y, 2) + pow(B.z, 2));
    float gocA_O_B = acos(a / (b * c));
    float kq = gocA_O_B * 180.0 / 3.14;
    return kq;
}

float program_4(Point A, Point B)
{
    float a = (A.x + B.x) / 2;
    float b = (A.y + B.y) / 2;
    float c = (A.z + B.z) / 2;
    float kq = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    return kq;
}

float program_5(Point A, Point B, Point C)
{
    float a = (A.x + B.x + C.x) / 3;
    float b = (A.y + B.y + C.y) / 3;
    float c = (A.z + B.z + C.z) / 3;
    float kq = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    return kq;
}

float program_6(Point A, Point B, Point C)
{
    float a = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2) + pow((B.z - A.z), 2));
    // Do dai AB
    float b = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2) + pow((C.z - A.z), 2));
    // Do dai AC
    float c = sqrt(pow((B.x - C.x), 2) + pow((B.y - C.y), 2) + pow((B.z - C.z), 2));
    // Do dai BC
    float p = (a + b + c) / 2;
    float kq = sqrt(p * (p - a) * (p - b) * (p - c));
    return kq;
}

int main()
{
    Point A, B, C;
    std::cout << "Nhap diem A: ";
    std::cin >> A.x >> A.y >> A.z;
    std::cout << "Nhap diem B: ";
    std::cin >> B.x >> B.y >> B.z;
    std::cout << "Nhap diem C: ";
    std::cin >> C.x >> C.y >> C.z;
    std::cout << "Ket qua 1: " << program_1(A) << "\n";
    std::cout << "Ket qua 2: " << program_2(A, B) << "\n";
    std::cout << "Ket qua 3: " << program_3(A, B) << "\n";
    std::cout << "Ket qua 4: " << program_4(A, B) << "\n";
    std::cout << "Ket qua 5: " << program_5(A, B, C) << "\n";
    std::cout << "Ket qua 6: " << program_6(A, B, C) << "\n";
}
