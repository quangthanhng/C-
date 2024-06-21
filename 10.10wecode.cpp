#include <iostream>
#include <string>
using namespace std;
#define MAX 100

struct DATHUC {
	int n;
	double heso[MAX];
	int somu[MAX];
};

DATHUC* Nhap(){
	DATHUC *P = new DATHUC;
	std::cin >> P->n;
	for(int i = 0; i < P->n ; i++){
		std::cin >> P->heso[i];
		std::cin >> P->somu[i];
	}
	return P;
}

void Xuat(const DATHUC &P){
	bool first = true;
	for(int i = 0; i < P.n ; i++){
		if(P.heso[i] != 0){	
			if (!first && P.heso[i] > 0) cout << "+";
			first = false;

			if(P.somu[i] == 0){
				cout << P.heso[i];
			}else{
				if(P.heso[i] == 1) cout << "x";
				else if(P.heso[i] == -1) cout << "-x";
				else cout << P.heso[i] << "x";

				if(P.somu[i] != 1) cout << "^" << P.somu[i];
			}
		}
    }
	if(first) cout << 0;
}

DATHUC& Tong2DaThuc(DATHUC *A, DATHUC *B) {
	DATHUC *C = new DATHUC;
	int a = 0, b = 0, c = 0;
	while (a < A->n || b < B->n) {
		if (a < A->n && b < B->n) {
			if (A->somu[a] == B->somu[b]) {
				if (A->heso[a] + B->heso[b] != 0) {
					C->heso[c] = A->heso[a] + B->heso[b];
					C->somu[c] = A->somu[a];
					c++;
				}
				a++;
				b++;
			} else if (A->somu[a] > B->somu[b]) {
				C->heso[c] = A->heso[a];
				C->somu[c] = A->somu[a];
				a++;
				c++;
			} else {
				C->heso[c] = B->heso[b];
				C->somu[c] = B->somu[b];
				b++;
				c++;
			}
		} else if (a < A->n) {
			C->heso[c] = A->heso[a];
			C->somu[c] = A->somu[a];
			a++;
			c++;
		} else {
			C->heso[c] = B->heso[b];
			C->somu[c] = B->somu[b];
			b++;
			c++;
		}
	}
	C->n = c;
	return *C;
}

int main() {
	DATHUC *A, *B;
	A = Nhap();
	B = Nhap();
	cout << "Da thuc A: "; Xuat(*A);
	cout << "\nDa thuc B: "; Xuat(*B);
	cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
	return 0;
}

/*
3
0 4
5 3
9 1
4
0 10
0 5
-5 3
-9 1	Da thuc A: 5x^3+9x
        Da thuc B: -5x^3-9x
        A+B = 0
*/