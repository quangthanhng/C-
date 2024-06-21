#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
    int x;
    cin >> x;
    if (x < 1 || x > 30)
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    else
    {
        cout << Fibo(x) << endl;
    }
    return 0;
}

int Fibo(int x)
{
    // 1 1 2 3 5 8 13 21
    if (x == 1)
        return 1;
    else
    {
        int sum = 0;
        int prev = 1;
        for(int i = 2; i <= x; i++){
            int imme_value = sum + prev;
            sum = prev;
            prev = imme_value;
        }
        return prev;
    }
}
