#include<iostream>
using namespace std;

void hanoi(int from, int to, int num){
	int temp = 6 - from - to;
	if(num == 1){
		cout << "move disc 1 from " << from
			 << " to " << to << endl;
	}
	else { 
		hanoi(from, temp, num - 1);
		cout << "move disc " << num << " from " << from
			 << " to " << to << endl;
		hanoi(temp, to, num - 1);
	}
}

int main(){
	int from = 1;
	int to = 2;
	int num = 10;
	hanoi(from, to, num);
}