#include <iostream>
#include <cmath>
using namespace std;

float program_1(int a[], int length)
{
    float tong = 0;
    float dem = 0;
    for (int i = 0; i < length; i += 2)
    {
        tong += a[i];
        dem += 1;
    }
    return (float)tong / dem;
}

float program_2(int a[], int length)
{
    float tong = 0;
    float dem = 0;
    for (int i = 1; i < length; i += 2)
    {
        tong += a[i];
        dem += 1;
    }
    return (float)tong / dem;
}

float program_3(int a[], int length)
{
    float temp = a[0];
    for (int i = 0; i < length; i++)
    {
        if (a[i] > temp)
        {
            temp = a[i];
        }
    }
    return temp;
}

float program_4(int a[], int length)
{
    float temp = a[0];
    for (int i = 0; i < length; i++)
    {
        if (a[i] < temp)
        {
            temp = i;
        }
    }
    return temp;
}

float program_5(int a[], int length)
{
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        if (sqrt(a[i]) == (int)sqrt(a[i]))
        {
            temp += 1;
        }
    }
    return temp;
}

float program_6(int a[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        bool isPrime = true;
        if (a[i] < 2)
            isPrime = false;
        for (int j = 2; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true)
            sum += a[i];
    }
    return sum;
}

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int find_mind_index(int a[], int start_index, int length)
{
    int min_index = start_index;
    for (int i = start_index; i < length; i++)
    {
        if (a[i] < a[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}
void program_7(int a[], int length)
{
    int temp;
    for (int i = 0; i < length; i++)
    {
        int min_index = find_mind_index(a, i, length);
        swap(a[i], a[min_index]);
    }
}

int main()
{
    const int MAX = 1000;
    int a[MAX];
    cout << "Nhap so luong phan tu: ";
    int n;
    cin >> n;

    cout << "Nhap lien tiep " << n << " gia tri: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Ket qua 1: " << program_1(a, n) << "\n";
    cout << "Ket qua 2: " << program_2(a, n) << "\n";
    cout << "Ket qua 3: " << program_3(a, n) << "\n";
    cout << "Ket qua 4: " << program_4(a, n) << "\n";
    cout << "Ket qua 5: " << program_5(a, n) << "\n";
    cout << "Ket qua 6: " << program_6(a, n) << "\n";

    cout << "Ket qua 7: ";
    program_7(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}