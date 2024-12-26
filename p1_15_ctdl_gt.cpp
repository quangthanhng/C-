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

// Duyệt và in danh sách
void iteration(const List& l) {
    if (l.pHead == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }
    node* temp = l.pHead;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

// Kiểm tra danh sách có tăng dần không (cho phép không giảm)
bool isIncreasing(const List& l) {
    if (l.pHead == nullptr || l.pHead->pNext == nullptr) {
        return false; // Danh sách rỗng hoặc chỉ có 1 phần tử không được coi là tăng dần
    }
    node* curr = l.pHead;
    bool check = true;
    while (curr->pNext != nullptr) {
        if(curr->info != curr->pNext->info){
            check = false;
        }
        if (curr->info > curr->pNext->info) { // Nếu phát hiện giảm
            return false;
        }
        curr = curr->pNext;
    }
    if(check == true) {
        return false;
    }
    return true; // Danh sách tăng dần hoặc không giảm
}

// Chèn phần tử vào danh sách tăng dần
void insertSorted(List& l, int x) {
    node* newNode = new node;
    newNode->info = x;
    newNode->pNext = nullptr;

    // Chèn vào đầu nếu danh sách rỗng hoặc giá trị nhỏ hơn đầu danh sách
    if (l.pHead == nullptr || x < l.pHead->info) {
        newNode->pNext = l.pHead;
        l.pHead = newNode;
        if (l.pTail == nullptr) l.pTail = newNode; // Nếu trước đó danh sách rỗng
        return;
    }

    // Chèn vào vị trí thích hợp
    node* curr = l.pHead;
    while (curr->pNext != nullptr && curr->pNext->info <= x) { // Cho phép bằng nhau
        curr = curr->pNext;
    }

    newNode->pNext = curr->pNext;
    curr->pNext = newNode;

    // Nếu chèn vào cuối danh sách
    if (newNode->pNext == nullptr) {
        l.pTail = newNode;
    }
}

int main() {
    List list;
    CreateList(list);
    int value;

    // Nhập các phần tử vào danh sách
    while (true) {
        cin >> value;
        if (value == 0) break;
        insert(list, value);
    }

    if (list.pHead == nullptr) {
        cout << "Danh sach rong." << endl;
        return 0;
    }

    // In danh sách vừa nhập
    cout << "Danh sach vua nhap la: ";
    iteration(list);

    // Kiểm tra nếu danh sách không tăng dần
    if (!isIncreasing(list)) {
        cout << "Danh sach khong tang." << endl;
        return 0;
    }

    // Nhập số x để chèn vào danh sách tăng dần
    int x;
    cin >> x;

    // Chèn x vào danh sách
    insertSorted(list, x);

    // In danh sách sau khi chèn
    cout << "Danh sach sau khi chen so " << x << " la: ";
    iteration(list);

    return 0;
}
