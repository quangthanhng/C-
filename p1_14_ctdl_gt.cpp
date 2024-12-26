
#include <iostream>
using namespace std;
struct node
{
    int info;
    node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void insert(List &l)
{
    int value;
    while (true)
    {
        cin >> value;
        if (value == 0)
            return;
        node *p = new node;
        p->info = value;
        p->pNext = NULL;
        if (l.pHead == NULL)
        {
            l.pHead = p;
            l.pTail = p;
        }
        else
        {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
}
void iteration(List l)
{
    for (node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
}
bool check(List l1, List l2){
    if(l1.pHead == NULL || l2.pHead == NULL)
    return false;
    return true;
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

void insertmerge(List& l, int value){
    node *p = new node;
        p->info = value;
        p->pNext = NULL;
        if (l.pHead == NULL)
        {
            l.pHead = p;
            l.pTail = p;
        }
        else
        {
            l.pTail->pNext = p;
            l.pTail = p;
        }
}

void mergelist(List l1, List l2){
    List temp;
    CreateList(temp);
    node* p1 = l1.pHead;
    node* p2 = l2.pHead;
    while(p1 != NULL && p2 != NULL){
        if(p1->info < p2->info){
            insertmerge(temp, p1->info);
            p1 = p1->pNext;
        }else {
            insertmerge(temp, p2->info);
            p2 = p2->pNext;
        }
    }
    for(; p1 != NULL; p1 = p1->pNext){
        insertmerge(temp, p1->info);
    }
    for(; p2 != NULL; p2 = p2->pNext){
        insertmerge(temp, p2->info);
    }
    for(node* p = temp.pHead; p != NULL; p = p->pNext){
        cout << p->info << " ";
    }
    cout << endl;
}

int main()
{
    List l1;
    List l2;
    CreateList(l1);
    CreateList(l2);
    insert(l1);
    insert(l2);
    if (l1.pHead == NULL)
        cout << "Danh sach l1 rong." << endl;
    else
    {
        cout << "Danh sach l1 la: ";
        iteration(l1);
        cout << endl;
    }
    if (l2.pHead == NULL)
        cout << "Danh sach l2 rong." << endl;
    else
    {
        cout << "Danh sach l2 la: ";
        iteration(l2);
        cout << endl;
    }
    if(!(check(l1, l2))){
        cout << "Khong tron duoc." << endl;
    }
    else {
        cout << "Danh sach l1 sau khi sap xep la: ";
        SortIncrease(l1);
        iteration(l1);
        cout << endl;
        cout << "Danh sach l2 sau khi sap xep la: ";
        SortIncrease(l2);
        iteration(l2);
        cout << endl;
        cout << "Ket qua tron l1 voi l2 la: ";
        mergelist(l1, l2);
    }
}