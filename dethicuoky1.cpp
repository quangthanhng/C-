#include <iostream>
using namespace std;

struct Node {
    char data;      
    Node* next;     
};

class Stack {
private:
    Node* top;  

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Hàm thêm một phần tử vào stack
    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rỗng! Không thể pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack rỗng! Không thể peek." << endl;
            return -1;  
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

char countMostFrequent() {
    int freq[256] = {0};
    Node* temp = top;
    while (temp != nullptr) {
        freq[temp->data]++;
        temp = temp->next;
    }

    int maxCount = 0;
    char mostFrequent = '\0';
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mostFrequent = static_cast<char>(i);
        }
    }
    return mostFrequent;
}

void removeMostFrequent(char mostFrequent) {
    Stack tempStack;
    while (!isEmpty()) {
        char current = peek();
        pop();
        if (current != mostFrequent) {
            tempStack.push(current);
        }
    }
    while (!tempStack.isEmpty()) {
        push(tempStack.peek());
        tempStack.pop();
    }
}

};

int main() {
    Stack stack;
    char c;
    while(true){
        cin >> c;
        if(c == '0')
        break;
        stack.push(c);
    }
    stack.display();
    char a = stack.countMostFrequent();
    cout << a << endl;
    stack.removeMostFrequent(a);
    stack.display();
    return 0;
}
