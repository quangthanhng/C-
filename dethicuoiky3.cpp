#include <iostream>
#include <cmath>
using namespace std;
#define max 100

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int a[], int value, int j) {
    while (j > 0 && a[j - 1] < value) {
        a[j] = a[j - 1];
        j--;
    }
    a[j] = value;  
}

void solution(int a[], int n) {
    for (int i = 1; i < n; i++) {
        insert(a, a[i], i);  
    }
    print(a, n);  
}

int findClosest(int a[], int n, double target) {
    int low = 0, high = n - 1;
    int closest = a[0];

    while (low <= high) {
        int mid = (low + high) / 2;

        if(abs(target - a[mid]) <= 0.5){
            closest = a[mid];
            return closest;
        }

        if (a[mid] > target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return closest;
}

int main() {
    int a[max];
    int n;
    cin >> n;  
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    int m;
    cin >> m;

    solution(a, n);  

    double sqrtM = sqrt(m);
    int closest = findClosest(a, n, sqrtM);

    cout << closest << endl;

    return 0;
}
