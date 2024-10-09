#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoublyLinkedList {
    Node* head = NULL;
    Node* tail = NULL;
};

void insert(DoublyLinkedList* list, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = newnode;
    }
    list->tail = newnode;
    if (list->head == NULL) {
        list->head = newnode;
    }
}

void deleteNode(DoublyLinkedList* list, int x) {
    Node* p = list->head;
    while (p != NULL) {
        if (p->data == x) {
            if (p->prev != NULL) {
                p->prev->next = p->next;
            } else {
                list->head = p->next;
            }
            if (p->next != NULL) {
                p->next->prev = p->prev;
            } else {
                list->tail = p->prev;
            }
            delete p;
            return;
        }
        p = p->next;
    }
}

void printList(DoublyLinkedList* list) {
    Node* p = list->head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    DoublyLinkedList list;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    printList(&list);

    deleteNode(&list, 2);
    printList(&list);

    deleteNode(&list, 1);
    printList(&list);

    deleteNode(&list, 3);
    printList(&list);

    return 0;
}