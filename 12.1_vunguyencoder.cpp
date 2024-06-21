/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 12 ****************************
********************** vunguyencoder.com **************************************

*******************************************************************************/

#include <iostream>

using namespace std;

struct Person
{
    Person(std::string fn)
    {
        fullname = fn;
    }
    string fullname;
};

void show_info(Person *p)
{
    // Noi dung can hoan thanh 
    cout << "\tDia chi: " << &p->fullname << endl;
    cout << "\tGia tri: " << p->fullname << endl;

}

/*
1 - Hàm show_info() in ra địa chỉ và dữ liệu của 1 person
2 - Viết hàm check_duplicate(Person* p1, Person *p2) để kiểm tra sự trùng lặp.
Hàm sẽ trả về 0 hoặc 1 hoặc 2 tùy theo các trường hợp sau: 
+ Địa chỉ vùng nhớ giống nhau: return 0
+ Địa chỉ vùng nhớ khác nhau nhưng dữ liệu (họ tên) giống nhau: return 1
+ Địa chỉ vùng nhớ và dữ liệu (họ tên) khác nhau: return 2 
Chương trình cần vượt qua các bài test như trong hình minh họa 
Lưu ý: ko sửa hàm main() và tham số của các hàm
*/

int check_duplicate(Person* p1, Person *p2)
{
    // Noi dung can hoan thanh 
    if(p1 == p2){
        return 0;
    }else if(p1 != p2 && p1->fullname == p2->fullname){
        return 1;
    }else return 2;
}

// Ko sua ham main 
int main()
{
    Person p1("Vu");
    Person *p2 = new Person("Fukada");
    Person *p3 = new Person("Tokuda");
    Person *p4 = new Person("Vu");
    Person *p5 = &p1;
    
    {
        cout << "Test 1 - Show info: \n";
        show_info(&p1);
    }
    
    {
        cout << "Test 2 - Show info: \n";
        show_info(p2);
    }
    
    {
        cout << "Test 3 - check_duplicate: \n";
        cout << "\t3.1 " << (check_duplicate(&p1, p2) == 2 ? "Pass" : "Failed") << "\n";
        cout << "\t3.2 " << (check_duplicate(&p1, p4) == 1 ? "Pass" : "Failed") << "\n";
        cout << "\t3.3 " << (check_duplicate(&p1, p5) == 0 ? "Pass" : "Failed") << "\n";
    }
}






