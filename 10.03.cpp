#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int id;
    std::string title;
};

void program_1(Book &book1, Book &book2)
{
    Book temp = book1;
    book1 = book2;
    book2 = temp;
}

void program_print_books(Book a[], int length)
{
    for (int i = 0; i < length; i++){
        cout << "\t" << a[i].id << " - " << a[i].title << endl;
    }
}
/*
(1) 1023;Dac nhan tam|8873;Bay vien ngoc rong|2372;Cha giau cha ngheo|900;Tham tu lung danh Conan|155;Tay Du Ky|231;Hong Lau Mong
(2) 22;Than thoai Bac Au|1000;Tham tu Sherlock Homes|87;Nguoi nhen|111;De che ky lan
*/

std::string program_2(Book a[], int length){
    int MAX = 0;
    int data = 0;
    for(int i = 0; i < length; i++){
        if(MAX < a[i].title.length()){
            MAX = a[i].title.length();
            data = i;
        }
    }
    return a[data].title;
}

float program_3(Book a[], int length){
    int Tong = 0;
    for(int i = 0; i < length; i++){
        Tong += a[i].title.length();
    }
    float kq = (float)Tong / (length);
    return kq;
}

void program_4(Book a[], int length){
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(a[j].title[0] < a[i].title[0]){
                program_1(a[j], a[i]);
            }
        }
    }
}
int main()
{
    Book a[100];
    int length = 0;
    std::string Data[30];
    std::string data;
    std::cout << "Nhap du lieu danh sach: ";
    std::getline(std::cin, data);

    // Phan tich du lieu
    int i = data.find('|');
    while (i != std::string::npos)
    {
        Data[length] = data.substr(0, i);
        data = data.substr(i + 1);
        length++;
        i = data.find('|');
    }
    Data[length++] = data;

    for (int i = 0; i < length; i++)
    {
        int j = Data[i].find(';');
        if (j != std::string::npos)
        {
            std::string id_str = Data[i].substr(0, j);
            std::string title_str = Data[i].substr(j + 1);
            // Chuyển chuỗi id thành số nguyên
            int id = std::stoi(id_str);
            // Gắn giá trị vào các đối tượng Book
            a[i].id = id;
            a[i].title = title_str;
        }
    }

    std::cout << "Ket qua 1: \n";
    program_1(a[0], a[length - 1]);
    program_print_books(a, length);

    std::cout << "Ket qua 2: " << program_2(a, length) << "\n";
    std::cout << "Ket qua 3: " << program_3(a, length) << "\n";
    std::cout << "Ket qua 4: " << "\n";
    program_4(a, length);
    program_print_books(a, length);
    return 0;
}