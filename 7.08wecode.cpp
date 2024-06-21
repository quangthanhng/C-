#include <iostream>
using namespace std;

#define MAX 100

void NhapMaTran(float a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

bool isFrobenius(float a[MAX][MAX], int m, int n) {
    if (m != n) {
        return false; // Ma trận không vuông
    }

    bool foundNonZeroColumn = false;
    int nonZeroColumn = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (a[i][j] != 1) {
                    return false; // Phần tử trên đường chéo chính không bằng 1
                }
            } else if (i > j) {
                if (a[i][j] != 0) {
                    if (foundNonZeroColumn) {
                        if (nonZeroColumn != j) {
                            return false; // Nhiều hơn một cột có phần tử khác 0 dưới đường chéo chính
                        }
                    } else {
                        foundNonZeroColumn = true;
                        nonZeroColumn = j;
                    }
                }
            } else {
                if (a[i][j] != 0) {
                    return false; // Phần tử trên đường chéo chính không bằng 0
                }
            }
        }
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    float a[MAX][MAX];
    NhapMaTran(a, m, n);
    cout << (isFrobenius(a, m, n) ? "Yes" : "No") << endl;
    return 0;
}
