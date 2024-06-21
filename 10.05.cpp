
/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 10.05 ****************************
********************** vunguyencoder.com **************************************

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Person {
	std::string ho_ten;
	int tuoi;
	
	Person() { ho_ten = ""; tuoi = -1; }
	Person(string ht, int t) { ho_ten = ht; tuoi = t;}
	
	void print_info() {
	    // Nội dung cần hoàn thành
        std::cout << "\t" << ho_ten << " - " << tuoi << " tuoi." << endl;
	}
};

void show_all(Person* people, int length) {
    // Nội dung cần hoàn thành
    for(int i = 0; i < length; i++){
        people[i].print_info();
    }
}

void append(Person* people, int& length, Person& new_person) {
    // Nội dung cần hoàn thành
    people[length] = new_person;
    length++;
}

void remove(Person* people, int& length, int index) {
    // Nội dung cần hoàn thành
    for(int i = index; i < length; i++){
        people[i] = people[i + 1];
    }
    length--;
}

std::string get_oldest_person(Person* people, int length) {
    // Nội dung cần hoàn thành
    int largest_age = 0;
    int position = 0;
    for(int i = 0; i < length; i++){
        if(people[i].tuoi > largest_age){
            largest_age = people[i].tuoi;
            position = i;
        }
    }
    return people[position].ho_ten;
}

void sort_person_list_by_age(Person* people, int length) {
    // Nội dung cần hoàn thành
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(people[j].tuoi < people[i].tuoi){
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main()
{
    const int MAX = 100;
    int length = 0;
	Person person_list[MAX];
	
	Person person_1("Anh Vu", 30);
	Person person_2("Eimi Fukada", 25);
	Person person_3("Ngoc Trinh", 27);
	Person person_4("Khac Tiep", 29);
	
	person_list[0] = person_1;length++;
	person_list[1] = person_2;length++;
	person_list[2] = person_3;length++;
	person_list[3] = person_4;length++;
	
	{
	    cout << "Test 1 - Print first person:\n";
	    person_list[0].print_info();
	}
	
	{
	    cout << "Test 2 - Print all person:\n";
	    show_all(person_list, length);
	}
	
	{
	    cout << "Test 3 - Append Tokuda:\n";
	    Person person_5("Tokuda", 60);
	    append(person_list, length, person_5);
	    show_all(person_list, length);
	}
	
	{
	    cout << "Test 4 - Remove Ngoc Trinh:\n";
	    remove(person_list, length, 2);
	    show_all(person_list, length);
	}
	
	{
	    cout << "Test 5 - Oldest person: ";
	    cout << get_oldest_person(person_list, length) << "\n";
	}
	
	{
	    cout << "Test 6 - Sort by age:\n";
	    sort_person_list_by_age(person_list, length);
	    show_all(person_list, length);
	}
}