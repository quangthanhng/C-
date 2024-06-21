#include <iostream>
using namespace std;
const int length_a = 3;
const int length_b = 2;
const int length_c = length_a + length_b;
const int length_d = length_a;
const int length_e = length_b;

void concatenate(int a[], int length_a, int b[], int length_b, int c[], int length_c)
{
    for (int i = 0; i < length_a; i++)
    {
        c[i] = a[i];
    }
    int j = 0;
    for (int i = length_a; i < length_c; i++)
    {
        c[i] = b[j];
        j++;
    }
}

void split(int d[], int length_d, int e[], int length_e, int c[], int length_c)
{
    for (int i = 0; i < length_a; i++)
    {
        d[i] = c[i];
    }
    int j = 0;
    for (int i = length_a; i < length_c; i++)
    {
        e[j] = c[i];
        j++;
    }
}

int main()
{
    int a[length_a] = {1, 2, 3};
    int b[length_b] = {4, 5};
    int c[length_c] = {};
    int d[length_a] = {};
    int e[length_b] = {};
    for (int x : a)
        cout << x << " ";
    cout << endl;
    for (int x : b)
        cout << x << " ";
    cout << endl;
    concatenate(a, length_a, b, length_b, c, length_c);
    for (int i = 0; i < length_c; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    split(d, length_d, e, length_e, c, length_c);
    for (int i = 0; i < length_d; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < length_e; i++)
    {
        cout << e[i] << " ";
    }
    return 0;
}