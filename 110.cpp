# include<iostream>
# include<math.h>
using namespace std;

int giaithua(int n){
    int sum;
    for(int i = 0; i <= n; i++){
        sum = 2*i + 1;
    }
    return sum;
}
int main(){
   int n;
   cout << " Nhap vao so n: ";
   cin >> n;
   double tong = 0;
   for(int i = 0; i <= n; i++){
    tong += (pow(-1, i)* 4)/ giaithua(i);
   } 
   cout << "Bieu thuc co gia tri la: " << tong;
    return 0;
}