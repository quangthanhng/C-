#include<iostream>
using namespace std;
#define max 100

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int a[], int value, int j){
    for( ; j > 0; j--){
        if(value > a[j - 1]){
            break;
        }
        a[j] = a[j - 1];
    }
    a[j] = value; 
}

void solution(int a[], int n){
    for(int i = 1; i < n; i++){
        insert(a, a[i], i);
    }
    print(a, n);
}

int main(){
    int a[max];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solution(a, n);
}

/////////////////////////////////// LINKED LIST ////////////////////////////////
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Hàm tạo một Node mới
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Hàm chèn một Node vào đầu danh sách
void push(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Hàm in danh sách
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm sắp xếp danh sách bằng Insertion Sort
void insertionSort(Node*& head) {
    if (!head || !head->next) return; // Trường hợp danh sách rỗng hoặc chỉ có một phần tử

    Node* sorted = nullptr; // Danh sách đã sắp xếp
    Node* current = head;

    while (current) {
        Node* next = current->next; // Lưu Node tiếp theo

        // Chèn current vào danh sách đã sắp xếp
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next; // Chuyển sang Node tiếp theo
    }

    head = sorted; // Cập nhật head thành danh sách đã sắp xếp
}

int main() {
    Node* head = nullptr;

    // Thêm các phần tử vào danh sách
    push(head, 5);
    push(head, 3);
    push(head, 8);
    push(head, 1);
    push(head, 7);

    cout << "Danh sach truoc khi sap xep: ";
    printList(head);

    // Sắp xếp danh sách
    insertionSort(head);

    cout << "Danh sach sau khi sap xep: ";
    printList(head);

    return 0;
}
