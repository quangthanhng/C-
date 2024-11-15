#include<iostream>
using namespace std;
void quicksort(int a[], int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(a, l, j);
    quicksort(a, i, r);
}

void insertionsort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void selectionsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }
    }
}
void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
void shellsort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
void sliding_window(int a[], int n, int k) {
    for (int i = 0; i < n - k + 1; i++) {
        int max = a[i];
        for (int j = 1; j < k; j++) {
            if (a[i + j] > max) {
                max = a[i + j];
            }
        }
        std::cout << max << " ";
    }
    std::cout << std::endl;
}

void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int j = i;
        int temp = a[j];
        int child = 2 * j + 1;
        while (child < n) {
            if (child + 1 < n && a[child] < a[child + 1]) {
                child++;
            }
            if (temp < a[child]) {
                a[j] = a[child];
                j = child;
                child = 2 * j + 1;
            } else {
                break;
            }
        }
        a[j] = temp;
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        int j = 0;
        temp = a[j];
        int child = 2 * j + 1;
        while (child < i) {
            if (child + 1 < i && a[child] < a[child + 1]) {
                child++;
            }
            if (temp < a[child]) {
                a[j] = a[child];
                j = child;
                child = 2 * j + 1;
            } else {
                break;
            }
        }
        a[j] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}