#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {
    Node* head;
    Node* tail;
    int length;

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void insertAtHead(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        length++;
    }

    void insertAtTail(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        length++;
    }

    void deleteNode(Node* node) {
        if (node == nullptr) return;
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        delete node;
        length--;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoubleLinkedList list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);
    list.insertAtTail(4);

    cout << "List displayed forward: ";
    list.displayForward();

    cout << "List displayed backward: ";
    list.displayBackward();

    list.deleteNode(list.head->next); // Delete the second node

    cout << "List after deletion: ";
    list.displayForward();

    return 0;
}