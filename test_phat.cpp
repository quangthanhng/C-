#include<iostream>
using namespace std;

struct Stack{
    int *arr;
    int length;

    Stack(){
        arr = NULL;
        length = 0;
    }
    ~Stack(){
        delete [] arr;
    }
    int& operator[](int index){
        return arr[index];
    }

    void push(int value){
        if(arr == NULL){
            arr = new int[1];
            arr[0] = value;
            length++;
            return;
        }
        int* temp_arr = new int[length + 1];
        for(int i  = 0; i < length; i++){
            temp_arr[i] = arr[i];
        }
        temp_arr[length++] = value;
        delete [] arr;
        arr = temp_arr;
    }
    int pop(){

    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(15);
}