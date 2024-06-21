#include <iostream>
using namespace std;
const int M = 2;
const int N = 3;
const int P = 2;
void program_1(int A[M][N][P], int b[], int& length)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < P; k++)
            {
                b[length] = A[i][j][k];
                length++;
            }
        }
    }
        for(int i = 0; i < length; i++){
        for(int j = i+1; j < length; j++){
            if( b[i] < b[j] ){
                int temp = b[i];
                b[i] = b[j];
                b[j]= temp;
            }
        }
    }
        for(int i = 0; i < length - 1; i++){
        for(int j = i+1; j < length; j++){
            if( b[i] == b[j] ){
                for(int k = j; k < length - 1; k++){
                    b[k] = b[k + 1];
                }
                length --;
                i--;
            }
        }
    }
    for(int i = 0; i < length; i++){
        cout << b[i] << " ";
    }
}

void program_2(int b[], int& length){
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(b[i] % b[j] == 0){
                cout << "(" << b[i] << ";" << b[j] <<")" << endl;
            }
        }
    }
}

void program_3(int b[], int& length){
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            for(int k = i + 2; k < length; k++){
                if(b[k] + b[j] == b[i] && b[j] > b[k]){
                    cout << b[i] << " = "  << b[j] << " + " << b[k] << endl;
                }
            }
        }
    }
}

int main()
{
    int length = 0;
    int b[1000] = {};
    int A[M][N][P] = {
        {{3, 2},
         {2, 7},
         {1, 8}},
        {{2, 9},
         {5, 8},
         {7, 20}}};
    cout << "Ket qua 1: "; program_1(A, b, length);
    cout << endl;
    cout << "Ket qua 2: " << endl; program_2(b, length);
    cout << "Ket qua 3: " << endl; program_3(b, length);
}