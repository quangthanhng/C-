#include <iostream>

using namespace std;

struct Vector
{
    int *arr;
    int length;
    Vector()
    {
        arr = NULL;
        length = 0;
    }
    ~Vector()
    {
        delete [] arr;
    }
    void push_back(int value){
        if(arr == NULL){
            arr = new int[1];
            arr[0] = value;
            length++;
            return;
        }
        int *temp_arr = new int[length+1];
        for(int i = 0; i < length; i++){
            temp_arr[i] = arr[i];
        }
        temp_arr[length++] = value;
        delete [] arr;
        arr = temp_arr;
    }
    int& operator[](int index){
        return arr[index];
    }
    int find(int value){
        
    }
};

int main()
{
    Vector v;
    v.push_back(10);
    v.push_back(15);
    v[0] = 3;
    std::cout << v[0] << " " << v[1] << "\n";
}