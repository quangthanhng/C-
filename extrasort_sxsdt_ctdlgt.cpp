#include<iostream>
#include<string>
using namespace std;

struct node {
    string s;
    node* pNext;
    
    node(string n) : s(n), pNext(nullptr) {};
};

struct List {
    node* pHead;
    node* pTail;
    
    List() : pHead(nullptr), pTail(nullptr) {};
};

void insertlist(List& l, string s) {
    node* tmp = new node(s);
    if (l.pHead == nullptr) {
        l.pHead = tmp;  // Nếu danh sách rỗng, gán pHead và pTail
        l.pTail = tmp;
    } else {
        l.pTail->pNext = tmp;
        l.pTail = tmp;  // Cập nhật pTail sau khi thêm phần tử mới
    }
}

bool check(string s1, string s2) {
    for (int i = 3; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] > s2[i]) {
            return true;
        } else if (s1[i] < s2[i]) {
            return false;
        }
    }
    return s1.length() > s2.length();  // So sánh độ dài nếu các ký tự giống nhau
}

node* split(node*& head) {
    if (head == nullptr || head->pNext == nullptr) {
        return nullptr;
    }

    node* slow = head;
    node* fast = head->pNext;

    while (fast != nullptr && fast->pNext != nullptr) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }

    node* secondhalf = slow->pNext;
    slow->pNext = nullptr;  // Cắt liên kết giữa 2 nửa
    return secondhalf;
}

node* Merge(node*& left, node*& right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    if (!check(left->s, right->s)) {
        left->pNext = Merge(left->pNext, right);
        return left;
    } else {
        right->pNext = Merge(left, right->pNext);
        return right;
    }
}

node* MergeSort(node*& head) {
    if (head == nullptr || head->pNext == nullptr) {
        return head;
    }

    node* mid = split(head);  // Chia danh sách thành 2 nửa
    node* left = MergeSort(head);
    node* right = MergeSort(mid);

    return Merge(left, right);  // Gộp lại 2 nửa đã sắp xếp
}

void print(List l) {
    node* cur = l.pHead;
    while (cur != nullptr) {
        cout << cur->s << endl;
        cur = cur->pNext;
    }
}

int main() {
    List l;
    while (true) {
        string n;
        cin >> n;
        if (n == "0") break;  // Dừng khi nhập "0"
        insertlist(l, n);
    }

    l.pHead = MergeSort(l.pHead);  // Gọi hàm MergeSort để sắp xếp danh sách

    print(l);  // In danh sách đã sắp xếp

    return 0;
}