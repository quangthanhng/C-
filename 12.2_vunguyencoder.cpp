
/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 12.02**************************
********************** vunguyencoder.com **************************************



*******************************************************************************/

#include <iostream>
#include <string>

/*
Biết có 1 cấu trúc là PersonList gồm 1 biến thành viên là 1 mảng quản lý tối đa 100 phần tử cấp phát động) cùng 1 biến count để đếm số phần tử đã được cấp phát. Hoàn thành các hàm thành viên của PersonList:
1 - Hàm show_all() in ra toàn bộ các Person trong mảng
2 - Hàm append() thêm một phần tử vào cuối mảng
3 - Hàm remove() xóa một phần tử tại vị trí bất kỳ trong mảng
4 - Hàm get_oldest_person() in ra Person có tuổi cao nhất
Chương trình cần vượt qua các bài test như hình dưới.
Lưu ý: ko sửa nội dung hàm main() và tham số của các hàm thành viên
*/

using namespace std;

const int MAX = 100;

struct Person
{
	std::string ho_ten;
	int tuoi;
	
	Person(): ho_ten(""), tuoi(-1) {}
	Person(string ht, int t) : ho_ten(ht), tuoi(t) {}
};

struct PersonList 
{
	Person *person_list[MAX];
	int count;
	
	PersonList()
	{
	    count = 0;
	}
	
    void show_all()
    {
        // Noi dung can hoan thanh 
        for(int i = 0; i < count; i++){
            cout << "\t" << person_list[i]->ho_ten << " - " << person_list[i]->tuoi << " tuoi.\n";
        }
    }
    
    void append(Person *new_person)
    {
        // Noi dung can hoan thanh 
        person_list[count++] = new_person;
    }
    
    void remove(int i)
    {
        // Noi dung can hoan thanh 
        for(int j = i; j < count; j++){
            person_list[j] = person_list[j + 1];
        }
        count--;
    }
    
    string get_oldest_person()
    {
        // Noi dung can hoan thanh 
        int oldest = person_list[0]->tuoi;
        int position;
        string oldest_people;
        for(int i = 0; i < count; i++){
            if(person_list[i]->tuoi > oldest){
                oldest = person_list[i]->tuoi;
                position = i;
            }
        }
        oldest_people = person_list[position]->ho_ten;
        return oldest_people;
    }
};

int main()
{
    PersonList *list = new PersonList;
    list->append(new Person("Anh Vu", 30));
    list->append(new Person("Eimi Fukada", 25));
    list->append(new Person("Ngoc Trinh", 27));
    list->append(new Person("Khac Tiep", 29));
    
	{
	    cout << "Test 1 - Print all person:\n";
	    list->show_all();
	}
	
	{
	    cout << "Test 2 - Append Tokuda:\n";
        list->append(new Person("Tokuda", 60));
	    list->show_all();
	}
	
	{
	    cout << "Test 3 - Remove Ngoc Trinh:\n";
	    list->remove(2);
	    list->show_all();
	}
	
	{
	    cout << "Test 4 - Oldest person: ";
	    cout << list->get_oldest_person() << "\n";
	}
}







