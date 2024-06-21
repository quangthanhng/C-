#include <iostream>
using namespace std;

void program_1(int a1[], int a2[], int length_a, int b[], int &length_b)
{
    for (int i = 0; i < length_a; i++)
    {
        for (int j = 0; j < length_a; j++)
        {
            if (a1[i] == a2[j])
            {
                length_b++;
                bool check = true;
                for (int k = 0; k < length_b; k++)
                {
                    if (b[k] == a2[j])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    b[length_b - 1] = a2[j];
                }
                else
                {
                    length_b--;
                }
                check = true;
            }
        }
    }
    for (int i = 0; i < length_b; i++)
    {
        cout << b[i] << " ";
    }
}

float program_2(int a1[], int a2[], int length_a)
{
    float count = 0;
    for (int i = 0; i < length_a; i++)
    {
        if (a1[i] == a2[i])
        {
            count += 1;
        }
    }
    return count / (float)length_a * 100;
}

bool program_3(int a1[], int a2[], int length_a)
{
    float count = 0;
    for (int i = 0; i < length_a; i++)
    {
        if (a1[i] >= a2[i])
        {
            count += 1;
        }
    }
    float result = count * 100 / length_a;
    if (result >= 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void delete_element(int c[], int& length_c, int x){
    for(int i = x; i < length_c; i++){
        c[i] = c[i+1];
    }
    length_c--;
}

void concatenate(int a1[], int a2[], int length_a, int c[], int& length_c){
    for(int i = 0; i < length_a; i++){
        c[length_c] = a1[i];
        length_c++;
    }
    for(int j = 0; j < length_a; j++){
        c[length_a+j] = a2[j];
        length_c++;
    }
    for(int i = 0; i < length_c; i++){
        for(int j = i+1; j < length_c; j++){
            if( c[i] == c[j]){
                delete_element(c, length_c, j);
                j--;
            }

        }
    }
}

int find_min_index(int c[], int& length_c, int start_index){
    int min_index = start_index;
    for(int i = min_index; i < length_c; i++){
        if( c[i] < c[min_index] ){
            min_index = i;
        }
    }
    return min_index;
}

void program_4(int a1[], int a2[], int length_a, int c[], int& length_c){
    concatenate(a1, a2, length_a, c, length_c);
    for(int i = 0; i < length_c; i++){
        int min_index = find_min_index(c, length_c, i);
        swap(c[i], c[min_index]);
    }
}

int main()
{
    int a1[1000];
    int a2[1000];
    int b[1000];
    int length_a = 0;
    int length_b = 0;
    cout << "Nhap so luong phan tu: ";
    cin >> length_a;
    cout << "Nhap lien tiep " << length_a << " gia tri cho a1: ";
    for (int i = 0; i < length_a; i++)
        cin >> a1[i];
    cout << "Nhap lien tiep " << length_a << " gia tri cho a2: ";
    for (int i = 0; i < length_a; i++)
        cin >> a2[i];
    {
        cout << "Ket qua 1: ";
        program_1(a1, a2, length_a, b, length_b);
        cout << endl;
        cout << "Ket qua 2: " << program_2(a1, a2, length_a) << "%\n";
        cout << "Ket qua 3: "
             << (program_3(a1, a2, length_a) ? "True" : "False") << "\n";
    }
    cout << "Ket qua 4: ";
    int c[1000];
    int length_c = 0;
    program_4(a1, a2, length_a, c, length_c);
    for(int i = 0; i < length_c; i++) cout << c[i] << " ";
}