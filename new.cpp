
/////////////////////*******(Nguyễn Quang Thành - 23521453)********//////////////////////////

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};


struct List
{
    Node *head;
    Node *tail;
    List()
    {
        head = tail = nullptr;
    }

    // Hàm thêm node vào cuối danh sách
    void append(int x)
    {
        Node *newNode = new Node(x);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Hàm in danh sách
    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Hàm tìm vị trí chèn bằng tìm kiếm nhị phân
    Node *binarySearch(Node *start, Node *end, int key)
    {
        Node *left = start;
        Node *right = end;
        Node *lastValid = nullptr;

        while (left != right)
        {
            Node *mid = left;
            Node *fast = left->next;

            // Xác định node giữa (mid)
            while (fast != right && fast->next != right)
            {
                mid = mid->next;
                fast = fast->next->next;
            }

            cout << "So sanh key " << key << " voi " << mid->data << endl;
            if (key < mid->data)
            {
                right = mid;
            }
            else
            {
                lastValid = mid; // Giữ lại mid nếu key >= mid->data
                left = mid->next;
            }
        }

        return lastValid; // Trả về node trước vị trí chèn
    }
};

void binaryInsertionSort(List &l)
{
    if (!l.head || !l.head->next)
        return; // Danh sách rỗng hoặc chỉ có một phần tử

    Node *sorted = l.head; // Phần đã sắp xếp ban đầu chỉ gồm phần tử đầu tiên
    Node *current = l.head->next;

    while (current)
    {
        Node *next = current->next; // Lưu lại node tiếp theo
        int key = current->data;
        cout << "\nKey: " << key << endl;

        // Tìm vị trí chèn cho key bằng tìm kiếm nhị phân
        Node *position = l.binarySearch(l.head, sorted->next, key);

        // In ra vị trí chèn dự kiến
        if (position == nullptr)
        {
            cout << "Chen " << key << " vao vi tri 0" << endl;
        }
        else
        {
            int posIdx = 0;
            Node *tmp = l.head;
            while (tmp != position)
            {
                tmp = tmp->next;
                posIdx++;
            }
            cout << "Chen " << key << " vao vi tri " << posIdx + 1 << endl;
        }

        if (position == sorted)
        {
            // Nếu chèn vào cuối phần đã sắp xếp
            sorted = current;
        }
        else
        {
            if (position == nullptr)
            {
                // Chèn vào đầu danh sách
                cout << "Chen " << key << " len dau\n";
                sorted->next = next; // Ngắt kết nối current khỏi danh sách
                current->next = l.head;
                l.head = current;
            }
            else
            {
                // Chèn vào giữa danh sách
                int currentPos = 0;
                Node *temp = l.head;
                while (temp != current)
                {
                    temp = temp->next;
                    currentPos++;
                }
                int insertPos = currentPos - 1;
                cout << "Chen " << key << " tu vi tri " << currentPos << " den vi tri " << insertPos << endl;

                sorted->next = next; // Ngắt kết nối current khỏi danh sách
                current->next = position->next;
                position->next = current;
            }
        }

        // In ra danh sách sau khi chèn
        cout << "Danh sach sau insertion: ";
        l.print();

        current = next;
    }
}

int main()
{
    List l;
    int x;

    cout << "Danh sach: ";
    while (cin >> x && x != 0)
    {
        l.append(x); // Thêm phần tử vào danh sách
    }

    cout << "Danh sach luc dau: ";
    l.print();

    binaryInsertionSort(l);

    cout << "Danh sach da sap xep: ";
    l.print();

    return 0;
}