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

void checkphantu(List& l) {
    for (node* p = l.pHead; p != NULL; p = p->pNext) {
        int count = 1;
        for (node* temp = p; temp->pNext != NULL;) {
            if (temp->pNext->info == p->info) {
                count++;
                node* cur = temp->pNext;
                temp->pNext = cur->pNext;
                delete cur;
                if (cur == l.pTail) {
                    l.pTail = temp; // Cập nhật lại đuôi danh sách nếu cần
                }
            } else {
                temp = temp->pNext; // Chỉ tiến tới nút tiếp theo nếu không xóa
            }
        }
        cout << p->info << ": " << count << endl;
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
    cout << "So lan xuat hien cua tung phan tu trong danh sach la: " << endl;
    checkphantu(list);
    return 0;
}
