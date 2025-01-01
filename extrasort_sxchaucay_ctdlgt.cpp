#include<iostream>
#include<string>
using namespace std;

struct node {
    int x;
    int y;
    node* pNext;
    
    node(int n, int m) : x(n), y(m), pNext(nullptr) {};
};

struct List {
    node* pHead;
    node* pTail;
    
    List() : pHead(nullptr), pTail(nullptr) {};
};

void insertlist(List& l, int n, int m){
    if (l.pHead == nullptr){
        node* tmp = new node(n,m);
        l.pHead = tmp;
        l.pTail = l.pHead;
        return;
    }
    else{
        node* tmp = new node(n,m);
        l.pTail -> pNext = tmp;
        l.pTail = tmp;
        return;
    }
}

void swap(node*& left, node*& right){
    if (left == nullptr || right == nullptr){return;}
    int so1 = left -> x;
    int so2 = left -> y;
    left -> x = right -> x;
    left -> y = right -> y;
    right -> x = so1;
    right -> y = so2;
}

void BubbleSort(List& l) {
    if (l.pHead == nullptr || l.pHead->pNext == nullptr) {
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        node* cur = l.pHead;
        while (cur != nullptr && cur->pNext != nullptr) {
            node* next = cur->pNext;
            if (cur->x > next->x) {
                int tempX = cur->x;
                int tempY = cur->y;
                cur->x = next->x;
                cur->y = next->y;
                next->x = tempX;
                next->y = tempY;
                swapped = true;
            }
            cur = cur->pNext;
        }
    } while (swapped);
}


node* split(node*& head){
    if (head == nullptr || head -> pNext == nullptr){ return nullptr;}
    
    node* slow = head;
    node* fast = head -> pNext;
    
    while (fast != nullptr && fast -> pNext != nullptr){
        slow = slow -> pNext;
        fast = fast -> pNext -> pNext;
    }
    
    node* secondhalf = slow -> pNext;
    slow -> pNext = nullptr;
    return secondhalf;
}

void print(List l){
    if (l.pHead == nullptr){return;}
    
    node* left = l.pHead;
    node* right = split(l.pHead);
    
    cout<<"1"<<endl;
    while (left != nullptr){
        cout << left -> x <<" "<< left -> y << endl;
        left = left -> pNext;
    }
    
    cout<<"2"<<endl;
    while(right != nullptr){
        cout << right -> x <<" " << right -> y << endl;
        right = right -> pNext;
    }
}

int main(){
    List l;
    while (true){
        int n, m;
        cin >> n;
        if (n!=0){
            cin>>m;
            insertlist(l, n, m);
        }
        else{
            break;
        }
    }
    
    BubbleSort(l);
    print(l);
    
    return 0;
}