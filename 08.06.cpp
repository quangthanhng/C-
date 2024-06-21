#include <iostream>
#include<cmath>
using namespace std;
const int a = 4;
const int b = 3;
int sumArray(int A[a][b])
{
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            sum += A[i][j];
        }
    }
    return sum;
}

int find_max_index(int A[a][b])
{
    int max_index = A[0][0];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (A[i][j] > max_index)
            {
                max_index = A[i][j];
            }
        }
    }
    return max_index;
}

void max_sub_array(int A[a][b])
{
    int sum_Array = 0;
    int position = 0;
    for (int i = 0; i < a; i++)
    {
        int sum_1_row = 0;
        for (int j = 0; j < b; j++)
        {
            sum_1_row += A[i][j];
        }
        if (sum_1_row >= sum_Array)
        {
            position = i;
            sum_Array = sum_1_row;
        }
    }
    for (int i = 0; i < b; i++)
    {
        cout << A[position][i] << " ";
    }
}

void is_prime(int A[a][b]){
    bool check = true;
    int prime;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 2; k <= sqrt(A[i][j]); k++){
                if( A[i][j] % k == 0){
                    check = false;
                    break;
                }
                check = true;
                prime = A[i][j];
            }
            if(check){
                cout << prime;
                break;
            }
        }
        if(check){
            break;
        }
    }
}

int main()
{
    int A[a][b] = {{8, 12, 9}, {4, 10, 13}, {15, 8, 20}, {12, 11, 10}};
    // for(int i = 0; i < a; i++){
    //     for(int j = 0; j < b; j++){
    //         cin >> A[i][j];
    //     }
    // }
    cout << "Ket qua 1: " << sumArray(A) << endl;
    cout << "Ket qua 2: " << find_max_index(A) << endl;
    cout << "Ket qua 3: ";
    max_sub_array(A);
    cout << endl;
    cout << "Ket qua 4: "; is_prime(A);
}