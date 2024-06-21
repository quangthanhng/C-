
/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 11.04 **************************
********************** vunguyencoder.com **************************************


*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

bool check_pointer(int *a, int n, int *p)
{
    // Nội dung cần hoàn thành
    // a: mảng số nguyên
    // n: số phần tử trong mảng a
    // p: con trỏ cần kiểm tra 
    // Hàm trả về:
    //  - true: nếu con trỏ trỏ vào phần tử nào đó trong mảng 
    //  - false: nếu con trỏ ko trỏ vào phần tử nào trong mảng 
    bool check = 0;
    for(int i = 0; i < n; i++){
        if(p == &a[i]){
            check = 1;
            break;
        }
    }
    return check;
}

bool check_same_pointers(int *a, int n, int *p1, int *p2)
{
    // Nội dung cần hoàn thành
    // a: mảng số nguyên
    // n: số phần tử trong mảng a
    // p1: con trỏ 1 cần kiểm tra 
    // p2: con trỏ 2 cần kiểm tra 
    // Hàm trả về:
    //  - true: nếu 2 con trỏ trỏ vào cùng 1 phần tử nào đó trong mảng 
    //  - false: nếu 2 con trỏ ko trỏ vào cùng 1 phần tử nào trong mảng 
    bool check = 0;
    for(int i = 0; i < n; i++){
        if( p1 == &a[i] && p2 == &a[i]){
            check = 1;
            break;
        }
    }
    return check;
}

int get_distance_in_byte(int *a, int n, int *p1, int *p2)
{
    // Nội dung cần hoàn thành
    // a: mảng số nguyên
    // n: số phần tử trong mảng a
    // p1: con trỏ 1 
    // p2: con trỏ 2 
    // Hàm trả về: 
    //    - Nếu p1 và p2 thuộc mảng, trả về khoảng cách giữa p1 và p2 
    //    - Nếu 1 trong 2 con trỏ ko thuộc mảng, trả về -1 
    bool check1 = 0, check2 = 0;
    for(int i = 0; i < n; i++){
        if( p1 == &a[i] ){
            check1 = 1;
        }
        if( p2 == &a[i] ){
            check2 = 1;
        }
    }
    if(check1 && check2){
        return abs(p1 - p2) * sizeof(int);
    }
    return -1;
}

int move_by_bytes_and_get_value(int *a, int n, int *p, int num_of_bytes)
{
    // Nội dung cần hoàn thành
    // a: mảng số nguyên
    // n: số phần tử trong mảng a
    // p: con trỏ 
    // num_of_bytes: số byte sẽ di chuyển 
    // Hàm trả về giá trị tại ô nhớ sau khi di chuyển con trỏ 
    int index;
    for(int i = 0; i < n; i++){
        if(p == &a[i]){
            index = i;
        }
    }
    
    if(num_of_bytes <= 0 || num_of_bytes % 4 != 0 || (n-index) * sizeof(int) < num_of_bytes){
        return -1;
    }
    int result;
    for(int i = 0; i < n; i++){
        if( p == &a[i] ){
            result = *(p + (num_of_bytes/ sizeof(int)));
        }
    }
    return result;
}

int main()
{
    // Sample data
    const int n = 7;
    int a[n] = { 3, 1, 2, 8, 6, 10, 15 };
    int *p1 = a + 1;
    int *p2 = a + 3;
    int *p3 = NULL;
    int *p4 = a + 8;
    int *p5 = p2 - 2;
    
    // Test cau 1
    {
        cout << "Test 1.1: " << (check_pointer(a, n, p1) == true ? "Pass" : "Failed") << "\n";
        cout << "Test 1.2: " << (check_pointer(a, n, p2) == true ? "Pass" : "Failed") << "\n";
        cout << "Test 1.3: " << (check_pointer(a, n, p3) == false ? "Pass" : "Failed") << "\n";
        cout << "Test 1.4: " << (check_pointer(a, n, p4) == false ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
    
    // Test cau 2
    {
        cout << "Test 2.1: " << (check_same_pointers(a, n, p1, p2) == false ? "Pass" : "Failed") << "\n";
        cout << "Test 2.2: " << (check_same_pointers(a, n, p1, p2-2) == true ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
    
    // Test cau 3
    {
        cout << "Test 3.1: " << (get_distance_in_byte(a, n, p1, p2) == 8 ? "Pass" : "Failed") << "\n";
        cout << "Test 3.2: " << (get_distance_in_byte(a, n, p1, a+8) == -1 ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
    
    // Test cau 4
    {
        cout << "Test 4.1: " << (move_by_bytes_and_get_value(a, n, p1, 4) == 2 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.2: " << (move_by_bytes_and_get_value(a, n, p1, 12) == 6 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.3: " << (move_by_bytes_and_get_value(a, n, p1, 3) == -1 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.4: " << (move_by_bytes_and_get_value(a, n, p1, -1) == -1 ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
}