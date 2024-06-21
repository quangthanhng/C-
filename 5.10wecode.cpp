#include <iostream>
using namespace std;

//ban: [ ], \*, /, %
// 5 4 = 1
// 990 88 = 22
int modulo(int m, int n){
    int a = m - n;
    if(a < 0){
        return a + n;
    }
    return modulo(a, n);
}


int main (){
    int m, n; cin >> m >> n;
	cout << modulo(m, n);
}