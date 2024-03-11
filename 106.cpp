# include<iostream>
# include<math.h>
using namespace std;

int giaithua(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= ((2*i) + 1)*(2*i);
    }
    return sum;
}
int main(){
   double x;
   int n;
   cout << " Nhap vao so x: ";
   cin >> x;
   cout << " Nhap vao so n: ";
   cin >> n;
   double tong = x;
   for(int i = 1; i <= n; i++){
    tong += (pow(-1, i)* pow( x, 2*i + 1))/ giaithua(i);
   } 
   cout << "Bieu thuc co gia tri la: " << tong;
    return 0;
}