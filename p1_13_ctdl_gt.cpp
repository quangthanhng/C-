
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
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
void SortIncrease(List& l);

void nhap(List& l){
    int value;
    while (true) {
        cin >> value;
        if (value == 0) return;
        node* p = new node;
        p->info = value;
        p->pNext = NULL;
        if(l.pHead == NULL){
            l.pHead = p;
            l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
}

void xuat(List l){
    for(node* p = l.pHead; p != NULL; p = p->pNext){
        cout << p->info << " ";
    }
    cout << endl;
}

void SortIncrease(List& l){
    for (node* i = l.pHead; i != nullptr; i = i->pNext) {
        node* minNode = i;
        for (node* j = i->pNext; j != nullptr; j = j->pNext) {
            if (j->info < minNode->info) {
                minNode = j; // Tìm node có giá trị nhỏ nhất
            }
        }
        // Hoán đổi giá trị giữa `i` và `minNode`
        if (minNode != i) {
            int temp = i->info;
            i->info = minNode->info;
            minNode->info = temp;
        }
    }
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        SortIncrease(l);
        cout << endl << "Danh sach sau khi sap xep la: ";
        xuat(l);
    }
    return 0;
}