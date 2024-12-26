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

void sort(List& l, int n) {
    List new_l;
    CreateList(new_l);

    // Xử lý phần tử đầu tiên nếu không chia hết cho n
    while (l.pHead != nullptr && l.pHead->info % n != 0) {
        node* p1 = l.pHead;
        l.pHead = l.pHead->pNext;
        insert(new_l, p1->info);
        delete p1;
    }

    // Xử lý các phần tử còn lại
    node* p = l.pHead;
    while (p != nullptr && p->pNext != nullptr) {
        if (p->pNext->info % n != 0) {
            node* temp = p->pNext;
            p->pNext = temp->pNext;
            insert(new_l, temp->info);
            delete temp;
            if (p->pNext == nullptr) {
                l.pTail = p; // Cập nhật lại đuôi danh sách
            }
        } else {
            p = p->pNext; // Di chuyển con trỏ
        }
    }

    // Ghép danh sách `new_l` vào cuối danh sách `l`
    if (l.pTail != nullptr) {
        l.pTail->pNext = new_l.pHead;
        if (new_l.pTail != nullptr) {
            l.pTail = new_l.pTail;
        }
    } else {
        // Nếu danh sách `l` ban đầu rỗng
        l.pHead = new_l.pHead;
        l.pTail = new_l.pTail;
    }

    // In danh sách sau khi sắp xếp
    iteration(l);
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
    int n;
    cin >> n;
    sort(list, n);
    return 0;
}
