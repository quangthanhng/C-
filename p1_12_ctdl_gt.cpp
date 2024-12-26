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

// Kiểm tra danh sách tăng/giảm
void check_tang_giam(const List& l) {
    if (l.pHead == nullptr || l.pHead->pNext == nullptr) {
        cout << "Danh sach khong tang cung khong giam." << endl;
        return;
    }

    bool tang = true, giam = true;
    node* curr = l.pHead;

    while (curr->pNext != nullptr) {
        if (curr->info < curr->pNext->info) {
            giam = false;
        } else if (curr->info > curr->pNext->info) {
            tang = false;
        }
        curr = curr->pNext;
    }

    if (tang && !giam) {
        cout << "Danh sach tang." << endl;
    } else if (!tang && giam) {
        cout << "Danh sach giam." << endl;
    } else {
        cout << "Danh sach khong tang cung khong giam." << endl;
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

    cout << "Danh sach vua nhap la: ";
    iteration(list);
    check_tang_giam(list);

    return 0;
}
