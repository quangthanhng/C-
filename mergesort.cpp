#include <iostream>
using namespace std;
#define max 100

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void combine(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Kích thước mảng trái
    int n2 = right - mid;     // Kích thước mảng phải

    // Tạo hai mảng tạm
    int L[n1], R[n2];

    // Sao chép dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng tạm lại vào mảng chính
    int i = 0; // Chỉ số của mảng trái
    int j = 0; // Chỉ số của mảng phải
    int k = left; // Chỉ số của mảng chính

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng trái (nếu còn)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng phải (nếu còn)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tìm chỉ số giữa mảng
        int mid = left + (right - left) / 2;

        // Gọi đệ quy cho nửa trái
        mergeSort(arr, left, mid);

        // Gọi đệ quy cho nửa phải
        mergeSort(arr, mid + 1, right);

        // Hợp nhất hai nửa
        combine(arr, left, mid, right);
    }
}
void solution(int a[], int n)
{
    mergeSort(a, 0, n - 1);
    print(a, n);
}

int main()
{
    int a[max];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solution(a, n);
}

/////////////////////////////////////Linked list/////////////////////////
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

// Hàm chia danh sách liên kết thành 2 nửa
Node* mergeSort(Node* head) {
    // Trường hợp cơ bản: nếu danh sách có 0 hoặc 1 phần tử, đã sắp xếp
    if (!head || !head->next) {
        return head;
    }

    // Chia đôi danh sách
    Node* mid = getMiddle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr; // Tách 2 nửa

    // Sắp xếp 2 nửa
    left = mergeSort(left);
    right = mergeSort(right);

    // Kết hợp 2 nửa đã sắp xếp
    return merge(left, right);
}

// Hàm tìm phần tử giữa của danh sách liên kết
Node* getMiddle(Node* head) {
    if (!head) return head;

    Node* slow = head;
    Node* fast = head;
    
    // Di chuyển fast 2 bước và slow 1 bước
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Hàm kết hợp hai danh sách đã sắp xếp thành một danh sách duy nhất
Node* merge(Node* left, Node* right) {
    // Nếu một trong hai danh sách rỗng, trả về danh sách còn lại
    if (!left) return right;
    if (!right) return left;

    // Chọn phần tử nhỏ hơn để nối vào danh sách kết quả
    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
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

    // Sắp xếp danh sách bằng Merge Sort
    head = mergeSort(head);

    cout << "Danh sách sau khi sắp xếp: ";
    printList(head);

    return 0;
}
