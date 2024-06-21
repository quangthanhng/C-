
/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 10.04 ****************************
********************** vunguyencoder.com **************************************

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Person
{
	std::string ho_ten;
	int tuoi;
};

Person create_person(string ho_ten, int tuoi)
{
	// Noi dung can hoan thanh
    Person New_person;
    New_person.ho_ten = ho_ten;
    New_person.tuoi = tuoi;
    return New_person;
}

void update_person(Person &person, string ho_ten, int tuoi)
{
	// Noi dung can hoan thanh
    person.ho_ten = ho_ten;
    person.tuoi = tuoi;
}

void copy_person(Person *person_1, Person *person_2)
{
	// Noi dung can hoan thanh
    person_1->tuoi = person_2->tuoi;
    person_1->ho_ten = person_2->ho_ten; 
}

int main()
{
	Person person_1 = create_person("Anh Vu", 30);

	Person person_2;
	update_person(person_2, "Eimi Fukada", 25);

	Person person_3;
	copy_person(&person_3, &person_2);
	person_3.ho_ten = "Ngoc Trinh";

	cout << "Danh sach person: \n";
	cout << person_1.ho_ten << " - " << person_1.tuoi << " tuoi.\n";
	cout << person_2.ho_ten << " - " << person_2.tuoi << " tuoi.\n";
	cout << person_3.ho_ten << " - " << person_3.tuoi << " tuoi.\n";
}
