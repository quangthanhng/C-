#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  int n,x;
  cin >> n >> x;
 long double s3 = 1,s1 = 1, s2 = 1,t=1,u=1;
  for (int i = 1; i <= n; i++) {
    s1 += pow(x,i);
  }

  for (int i = 2; i <= 2*n; i+=2) {
    s2 += pow(x,i);
  }

  for (int i = 1; i <= n; i++) {
    t*=i;
    u=u*x;
    s3+=u/t;
  }

  cout <<s1 << endl;
  cout <<s2 << endl;
  cout <<s3 << endl;

  return 0;
}