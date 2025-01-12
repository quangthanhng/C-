#include<iostream>
using namespace std;
#define max 100

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
 
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void solution(int a[], int n){
    bool check = true;
    for( ;check == true; ){
        check = false;
        for(int i = 0; i <= n - 2; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                check = true;
            }
        }
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

///////////////////////////////////////Linked list///////////////////////
#include <iostream>
using namespace std;

// Định nghĩa nút của Linked List
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Hàm thêm một nút vào cuối danh sách
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm thực hiện thuật toán Bubble Sort trên Linked List sử dụng vòng lặp for
void bubbleSort(Node* head) {
    if (!head || !head->next) return;  // Nếu danh sách có 0 hoặc 1 phần tử thì không cần sắp xếp

    bool swapped;
    for (Node* i = head; i != nullptr; i = i->next) { // Vòng lặp bên ngoài
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        // Vòng lặp bên trong, kiểm tra từng cặp nút liên tiếp
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                // Hoán đổi dữ liệu giữa j và j->next
                if (prev) {
                    prev->next = j->next;
                } else {
                    head = j->next;  // Nếu là phần tử đầu tiên, cập nhật head
                }

                Node* temp = j->next;
                j->next = temp->next;
                temp->next = j;
                prev = temp;
                swapped = true;
            } else {
                prev = j;
            }
        }
        
        // Nếu không có sự thay đổi trong lần lặp này, danh sách đã được sắp xếp
        if (!swapped) {
            break;
        }
    }
}

int main() {
    Node* head = nullptr;

    // Thêm các phần tử vào danh sách
    append(head, 64);
    append(head, 34);
    append(head, 25);
    append(head, 12);
    append(head, 22);
    append(head, 11);

    cout << "Danh sách trước khi sắp xếp: ";
    printList(head);

    // Sắp xếp danh sách bằng Bubble Sort
    bubbleSort(head);

    cout << "Danh sách sau khi sắp xếp: ";
    printList(head);

    return 0;
}

