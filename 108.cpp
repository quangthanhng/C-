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
   double x;
   int n;
   cout << " Nhap vao so x: ";
   cin >> x;
   cout << " Nhap vao so n: ";
   cin >> n;
   double tong = 1;
   for(int i = 1; i <= n; i++){
    tong += pow(x,i)/giaithua(i);
   } 
   cout << "Bieu thuc co gia tri la: " << tong;
    return 0;
}