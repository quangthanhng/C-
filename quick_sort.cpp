#include <iostream>

using namespace std;

#define MAX 100

int a[MAX];
int n;

void swap(int &m, int &n)
{
    int temp = m;
    m = n;
    n = temp;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int partition(int start, int end)
{
    int pivot_value = a[end];
    int i_small = start - 1;
    for (int i = start; i < end; i++)
    {
        if (a[i] < pivot_value)
        {
            swap(a[i], a[++i_small]);
        }
    }
    swap(a[end], a[i_small + 1]);
    return i_small++;
}

void quicksort(int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // a[pivot] = pivot_value
    int pivot = partition(start, end);
    // start -> pivot - 1
    quicksort(start, pivot - 1);
    quicksort(pivot + 1, end);
    // pivot + 1 -> end
}

void solution()
{
    quicksort(0, n - 1);
    print();
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solution();
}