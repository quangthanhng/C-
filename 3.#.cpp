#include <iostream>
#include <cmath>
using namespace std;

int result1(int n) {
	int sum = 0;
	int s1 = 1;
    for (int j = 1; j <= i; j++) {
			s1 = s1 * i;
		}
	for (int i = 1; i <= n; i++) {
		sum = sum + s1;
	}
	return sum;
}
int result2 (int n) {
	int sum = 0;
	int s2 = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			s2 = s2 * j;
		}
		sum = sum + s2;
	}
	return sum;
}
double result3 (int n) {
	double sum = 0;
	double s3 = 0;
	for (int i = 1; i <= n; i++) {
		sum = sum + i;
		s3 = s3 + (1 / s3);
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	double x = double(n);
	cout << result1(n) << endl;
	cout << result2(n) << endl;
	cout << result3(n);
	return 0;
}

