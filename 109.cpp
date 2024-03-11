# include<iostream>
# include<math.h>
using namespace std;

int giaithua(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    return sum;
}
int main(){
   int n;
   cout << " Nhap vao so n: ";
   cin >> n;
   double tong = 1;
   for(int i = 1; i <= n; i++){
    tong += (double)1/giaithua(i);
   } 
   cout << "Bieu thuc co gia tri la: " << tong;
    return 0;
}