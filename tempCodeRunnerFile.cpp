#include <iostream>
using namespace std;

struct Node {
    int numerator;
    int denominator;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int numerator, int denominator) {
        if (denominator == 0) return;
        Node* newNode = new Node();
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        if (!head) {
            cout << "Danh sach rong." << endl;
            return;
        }
        cout << "Danh sach vua nhap la: ";
        Node* temp = head;
        while (temp) {
            cout << temp->numerator << "/" << temp->denominator << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printEqualRationals(int xNumerator, int xDenominator) {
        if (!head) {
            cout << "Khong co phan so nao bang " << xNumerator << "/" << xDenominator << " trong danh sach." << endl;
            return;
        }
        bool found = false;
        Node* temp = head;
        while (temp) {
            if (temp->numerator * xDenominator == temp->denominator * xNumerator) {
                if (!found) {
                    cout << "Cac phan so bang " << xNumerator << "/" << xDenominator << " co trong danh sach la: ";
                    found = true;
                }
                cout << temp->numerator << "/" << temp->denominator << " ";
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Khong co phan so nao bang " << xNumerator << "/" << xDenominator << " trong danh sach." << endl;
        } else {
            cout << endl;
        }
    }

private:
    Node* head;
};

int main() {
    LinkedList list;
    int numerator, denominator;

    while (true) {
        cin >> numerator >> denominator;
        if (denominator == 0) break;
        list.insert(numerator, denominator);
    }

    list.printList();

    cin >> numerator >> denominator;
    list.printEqualRationals(numerator, denominator);

    return 0;
}