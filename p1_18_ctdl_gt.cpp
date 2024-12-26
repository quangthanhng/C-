#include <iostream>
using namespace std;

struct node {
    int info;
    node* pNext;
};

struct List {
    node* pHead;
    node* pTail;
};

// Khởi tạo danh sách liên kết
void CreateList(List& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

// Thêm phần tử vào cuối danh sách
void insert(List& l, int value) {
    node* newNode = new node;
    newNode->info = value;
    newNode->pNext = nullptr;
    if (l.pHead == nullptr) {
        l.pHead = newNode;
        l.pTail = newNode;
    } else {
        l.pTail->pNext = newNode;
        l.pTail = newNode;
    }
}

bool check_prime(int value){
    if(value <= 1)
    return false;
    for(int i = 2; i*i <= value; i++){
        if(value % i == 0){
            return false;
        }
    }
    return true;
}

void print_even_element(List l){
    int position = 0;
    for(node* p = l.pHead; p != NULL; p = p->pNext){
        position++;
        if(position % 2 == 0 && check_prime(p->info) == true){
            cout << p->info << " ";
        }
    }
}



int main() {
    List list;
    CreateList(list);
    int value;

    while (true) {
        cin >> value;
        if (value == 0) break;
        insert(list, value);
    }

    if (list.pHead == nullptr) {
        cout << "Danh sach rong." << endl;
        return 0;
    }
    print_even_element(list);
    return 0;
}
