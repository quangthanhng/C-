#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void initStack(Stack &s) {
    s.top = NULL;
}

bool isEmpty(Stack s) {
    return s.top == NULL;
}

void push(Stack &s, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        return -1; // Trả về -1 để biểu thị stack rỗng
    }
    Node* temp = s.top;
    int poppedValue = temp->data;
    s.top = s.top->next;
    delete temp;
    return poppedValue;
}

void printStack(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack rong." << endl;
        return;
    }
    cout << "Cac gia tri co trong stack la: ";
    Node* current = s.top;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Stack s;
    initStack(s);
    int x;
    cin >> x;
    int n;
    bool check = true;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        } else if (n == x) {
            if (!isEmpty(s)) {
                pop(s);
            } else if (check) {
                cout << "Stack rong." << endl;
                check = false;
            }
        } else {
            push(s, n);
        }
    }

    if (isEmpty(s)) {
        cout << "Stack rong." << endl;
    } else {
        printStack(s);
    }

    return 0;
}