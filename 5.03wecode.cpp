#include <iostream>
using namespace std;

int largest_input(){
int num;
cin >> num;
if (num==0){
    return 0;
}
int nextNum = largest_input();
return (num > nextNum) ? num : nextNum;
}
int main(){
	cout << largest_input();
}
