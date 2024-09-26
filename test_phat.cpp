#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
    string name;
    void set_salary(const double potential_salary){
        salary = potential_salary;
    }
    double get_salary(){
        return salary;
    }
    private:
    double salary;
};

int main(){
    Employee nv1;
    nv1.name = "Kevin";
    cout << nv1.name << endl;
    nv1.set_salary(50000);
    cout << nv1.get_salary() << endl;
}