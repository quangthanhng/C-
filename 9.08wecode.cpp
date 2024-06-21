#include <iostream>
using namespace std;

#define MAXR 100
#define MAXC 100

void NhapMaTran(float a[MAXR][MAXC], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void XuatGTLN(float a[MAXR][MAXC], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = a[0][i];
        for (int j = 0; j < m; j++)
        {
            if(a[j][i] > value){
                value = a[j][i];
            }
        } 
        cout << "Gia tri lon nhat tren cot " << i << " la: " << value << endl;
    }
}



int main()
{
    int m, n;
    cin >> m >> n;
    float a[MAXR][MAXC];
    NhapMaTran(a, m, n);
    XuatGTLN(a, m, n);
}