#include <iostream>
using namespace std;

#define MAX 100

void NhapMaTran(float a[MAX][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void TichMaTran(float a[MAX][MAX], int m, int n, float b[MAX][MAX], int k, float c[MAX][MAX])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            c[i][j] = 0; // Khởi tạo giá trị ban đầu cho phần tử c[i][j]
            for (int z = 0; z < n; z++)
            {
                c[i][j] += a[i][z] * b[z][j];
            }
        }
    }
}

int main()
{
    int m, n, l, k;
    cin >> m >> n;
    float a[MAX][MAX];
    float b[MAX][MAX];
    NhapMaTran(a, m, n);
    cin >> l >> k;
    if (l != n)
    {
        cout << "Ma tran nhap sai" << endl;
        return 1;
    }
    else
    {
        NhapMaTran(b, l, k);
        float c[MAX][MAX];
        TichMaTran(a, m, n, b, k, c);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
